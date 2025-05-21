#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

public ref class PieChartPanel : public Panel
{
private:
    Dictionary<String^, float>^ data;
    array<Color>^ colors;
    int highlightedIndex;
    float animationProgress;

public:
    PieChartPanel()
    {
        this->DoubleBuffered = true;
        this->BackColor = Color::FromArgb(40, 40, 45); // Dark background
        data = gcnew Dictionary<String^, float>();
        highlightedIndex = -1;
        animationProgress = 0.0f;

        // Vibrant color palette with better contrast
        colors = gcnew array<Color> {
            Color::FromArgb(255, 99, 132),   // Red
                Color::FromArgb(54, 162, 235),   // Blue
                Color::FromArgb(255, 159, 64),   // Orange
                Color::FromArgb(75, 192, 192),   // Teal
                Color::FromArgb(153, 102, 255),  // Purple
                Color::FromArgb(255, 205, 86),   // Yellow
                Color::FromArgb(201, 203, 207)   // Gray
        };

        // Enable mouse interaction
        this->MouseMove += gcnew MouseEventHandler(this, &PieChartPanel::OnMouseMove);
        this->MouseLeave += gcnew EventHandler(this, &PieChartPanel::OnMouseLeave);
    }

    void SetData(Dictionary<String^, float>^ inputData)
    {
        if (inputData == nullptr || inputData->Count == 0)
        {
            data->Clear();
        }
        else
        {
            data = inputData;
        }

        // Reset animation
        animationProgress = 0.0f;
        this->Invalidate();

        // Start animation timer if not already running
        if (animationProgress < 1.0f)
        {
            Timer^ animationTimer = gcnew Timer();
            animationTimer->Interval = 16; // ~60fps
            animationTimer->Tick += gcnew EventHandler(this, &PieChartPanel::OnAnimationTick);
            animationTimer->Start();
        }
    }

protected:
    virtual void OnPaint(PaintEventArgs^ e) override
    {
        __super::OnPaint(e);

        Graphics^ g = e->Graphics;
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

        if (data == nullptr || data->Count == 0)
        {
            // Draw "No Data" message with white text
            StringFormat^ format = gcnew StringFormat();
            format->Alignment = StringAlignment::Center;
            format->LineAlignment = StringAlignment::Center;

            g->DrawString("No data available",
                gcnew System::Drawing::Font("Arial", 12, FontStyle::Italic),
                Brushes::White,
                this->ClientRectangle,
                format);
            return;
        }

        // Calculate total
        float total = 0.0f;
        for each (KeyValuePair<String^, float> ^ kvp in data)
        {
            total += kvp->Value;
        }

        if (total <= 0.0f) return;

        // Draw pie chart with animation
        int diameter = Math::Min(this->Width, this->Height) - 80;
        Rectangle rect(
            static_cast<int>((this->Width - diameter) / 2.0f),
            40,
            diameter,
            diameter);

        // Draw chart shadow
        Rectangle shadowRect = rect;
        shadowRect.Offset(3, 3);
        g->FillPie(gcnew SolidBrush(Color::FromArgb(30, Color::Black)), shadowRect, 0, 360);

        float startAngle = 0.0f;
        int colorIndex = 0;

        // Draw pie slices with animation
        for each (KeyValuePair<String^, float> ^ kvp in data)
        {
            float percentage = kvp->Value / total;
            float sweepAngle = percentage * 360.0f * animationProgress;

            Color sliceColor = colors[colorIndex % colors->Length];

            // Highlight the slice under mouse
            if (colorIndex == highlightedIndex)
            {
                sliceColor = Color::FromArgb(
                    Math::Min(255, sliceColor.R + 40),
                    Math::Min(255, sliceColor.G + 40),
                    Math::Min(255, sliceColor.B + 40));

                // Draw highlight effect
                Rectangle highlightRect = rect;
                highlightRect.Inflate(5, 5);
                g->FillPie(gcnew SolidBrush(sliceColor), highlightRect, startAngle, sweepAngle);
            }

            g->FillPie(gcnew SolidBrush(sliceColor), rect, startAngle, sweepAngle);

            // Draw slice border
            g->DrawPie(gcnew Pen(Color::FromArgb(150, Color::White)), rect, startAngle, sweepAngle);

            startAngle += sweepAngle;
            colorIndex++;
        }

        // Draw legend with white text
        int legendX = 20;
        int legendY = this->Height - 30 - (data->Count * 25);
        int legendItemHeight = 25;
        colorIndex = 0;

        for each (KeyValuePair<String^, float> ^ kvp in data)
        {
            float percentage = kvp->Value / total;
            Color sliceColor = colors[colorIndex % colors->Length];

            // Legend color box with shadow
            Rectangle legendColorRect(legendX, legendY, 18, 18);
            g->FillRectangle(gcnew SolidBrush(Color::FromArgb(30, Color::Black)), legendColorRect.X + 1, legendColorRect.Y + 1, legendColorRect.Width, legendColorRect.Height);
            g->FillRectangle(gcnew SolidBrush(sliceColor), legendColorRect);

            // Legend text with white color
            g->DrawString(String::Format("{0} ({1:P1})", kvp->Key, percentage),
                gcnew System::Drawing::Font(this->Font, FontStyle::Bold),
                Brushes::White,
                static_cast<float>(legendX + 25),
                static_cast<float>(legendY));

            // Draw value in smaller font
            g->DrawString(String::Format("{0:N0}", kvp->Value),
                gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->Size - 2),
                Brushes::LightGray,
                static_cast<float>(legendX + 25),
                static_cast<float>(legendY + 16));

            colorIndex++;
            legendY += legendItemHeight;
        }

        // Draw title with white text
        if (!String::IsNullOrEmpty(this->Text))
        {
            StringFormat^ titleFormat = gcnew StringFormat();
            titleFormat->Alignment = StringAlignment::Center;
            g->DrawString(this->Text,
                gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold),
                Brushes::White,
                PointF(this->Width / 2.0f, 10),
                titleFormat);
        }
    }

private:
    void OnAnimationTick(Object^ sender, EventArgs^ e)
    {
        animationProgress += 0.05f;
        if (animationProgress >= 1.0f)
        {
            animationProgress = 1.0f;
            safe_cast<Timer^>(sender)->Stop();
        }
        this->Invalidate();
    }

    void OnMouseMove(Object^ sender, MouseEventArgs^ e)
    {
        if (data == nullptr || data->Count == 0) return;

        int diameter = Math::Min(this->Width, this->Height) - 80;
        Rectangle rect(
            static_cast<int>((this->Width - diameter) / 2.0f),
            40,
            diameter,
            diameter);

        Point center = Point(rect.X + rect.Width / 2, rect.Y + rect.Height / 2);
        float dx = static_cast<float>(e->X) - static_cast<float>(center.X);
        float dy = static_cast<float>(e->Y) - static_cast<float>(center.Y);

        float distance = (float)Math::Sqrt(dx * dx + dy * dy);

        if (distance <= diameter / 2)
        {
            float angle = (float)(Math::Atan2(dy, dx) * 180.0f / (float)Math::PI);
            if (angle < 0) angle += 360;

            float total = 0.0f;
            for each (KeyValuePair<String^, float> ^ kvp in data)
            {
                total += kvp->Value;
            }

            float startAngle = 0.0f;
            int newHighlight = -1;
            int colorIndex = 0;

            for each (KeyValuePair<String^, float> ^ kvp in data)
            {
                float sweepAngle = (kvp->Value / total) * 360.0f;
                if (angle >= startAngle && angle < startAngle + sweepAngle)
                {
                    newHighlight = colorIndex;
                    break;
                }
                startAngle += sweepAngle;
                colorIndex++;
            }

            if (highlightedIndex != newHighlight)
            {
                highlightedIndex = newHighlight;
                this->Invalidate();
            }
        }
        else if (highlightedIndex != -1)
        {
            highlightedIndex = -1;
            this->Invalidate();
        }
    }

    void OnMouseLeave(Object^ sender, EventArgs^ e)
    {
        if (highlightedIndex != -1)
        {
            highlightedIndex = -1;
            this->Invalidate();
        }
    }
};