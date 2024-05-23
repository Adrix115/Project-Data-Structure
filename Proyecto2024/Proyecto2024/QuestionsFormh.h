#pragma once

#pragma once

namespace Proyecto2024 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class QuestionsForm : public System::Windows::Forms::Form
    {
    public:
        QuestionsForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~QuestionsForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ListBox^ questionsListBox;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->questionsListBox = (gcnew System::Windows::Forms::ListBox());
            this->SuspendLayout();
            // 
            // questionsListBox
            // 
            this->questionsListBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->questionsListBox->ItemHeight = 20;
            this->questionsListBox->FormattingEnabled = true;
            this->questionsListBox->Location = System::Drawing::Point(12, 12);
            this->questionsListBox->Name = L"questionsListBox";
            this->questionsListBox->Size = System::Drawing::Size(760, 420);
            this->questionsListBox->TabIndex = 0;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            // Add questions to the list box
            this->questionsListBox->Items->AddRange(gcnew cli::array<String^>{
                "What key features should be included in the main dashboard of the application?",
                    "How can the application be designed to be user-friendly for both tech-savvy and non-tech-savvy mothers?",
                    "What color schemes and design elements would appeal to mothers and children?",
                    "How can the app provide easy navigation and accessibility for its users?",
                    "What age-specific content should be available for children within the app?",
                    "What kind of health tracking features would be beneficial for mothers and their children?",
                    "How can the app integrate with wearable devices to monitor the health metrics of mothers and children?",
                    "What type of reminders and alerts could help mothers manage their children’s health appointments and medication schedules?",
                    "How can the app provide personalized health tips and advice for different age groups?",
                    "What partnerships with healthcare providers or pediatricians could enhance the app’s value?",
                    "What educational content should be included to support the development of children?",
                    "How can the app encourage and track educational milestones and achievements?",
                    "What features can help mothers find and enroll their children in local educational programs and activities?",
                    "How can the app provide resources for mothers to support their children’s learning at home?",
                    "What tools can the app offer to monitor and manage screen time effectively?",
                    "How can the app facilitate a community of mothers for sharing tips, advice, and support?",
                    "What types of forums or discussion boards would be valuable for mothers to connect?",
                    "How can the app offer access to professional advice from pediatricians, child psychologists, and other experts?",
                    "What event planning or coordination features could help mothers organize playdates and group activities?",
                    "How can the app include mental health resources and support for mothers?",
                    "What measures should be taken to ensure the safety and privacy of the users’ data?",
                    "How can the app verify the identity of users to create a secure community?",
                    "What parental controls should be available to protect children’s information and usage?",
                    "How can the app provide emergency contact features for quick access to help when needed?",
                    "What guidelines should the app follow to comply with data protection regulations?",
                    "What kind of activities and games can the app include to entertain and educate children?",
                    "How can the app offer suggestions for age-appropriate activities based on the child’s development stage?",
                    "What features can help mothers find local family-friendly events and activities?",
                    "How can the app incorporate multimedia content like stories, songs, and videos for children?",
                    "What types of interactive content can engage children while supporting learning?",
                    "What feedback mechanisms should be implemented to continuously improve the app?",
                    "How can the app gather insights on user satisfaction and areas for improvement?",
                    "What features could encourage users to provide regular feedback?",
                    "How can the app track usage patterns to identify popular features and potential issues?",
                    "What strategies can be employed to keep the app updated with the latest content and features?"
            });

            // 
            // QuestionsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 461);
            this->Controls->Add(this->questionsListBox);
            this->Name = L"QuestionsForm";
            this->Text = L"Questions";
            this->ResumeLayout(false);
        }
#pragma endregion
    };
}
