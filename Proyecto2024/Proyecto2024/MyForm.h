#pragma once

#include "QuestionsFormh.h"

namespace Proyecto2024 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ chatbotMessageLabel;
        System::Windows::Forms::Button^ askButton;
        System::Windows::Forms::Button^ showQuestionsButton;
        System::Windows::Forms::TextBox^ questionTextBox;
        System::Windows::Forms::TextBox^ answerTextBox;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->chatbotMessageLabel = (gcnew System::Windows::Forms::Label());
            this->askButton = (gcnew System::Windows::Forms::Button());
            this->showQuestionsButton = (gcnew System::Windows::Forms::Button());
            this->questionTextBox = (gcnew System::Windows::Forms::TextBox());
            this->answerTextBox = (gcnew System::Windows::Forms::TextBox());
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->SuspendLayout();
            // 
            // chatbotMessageLabel
            // 
            this->chatbotMessageLabel->AutoSize = true;
            this->chatbotMessageLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->chatbotMessageLabel->Location = System::Drawing::Point(484, 85);
            this->chatbotMessageLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->chatbotMessageLabel->Name = L"chatbotMessageLabel";
            this->chatbotMessageLabel->Size = System::Drawing::Size(345, 29);
            this->chatbotMessageLabel->TabIndex = 0;
            this->chatbotMessageLabel->Text = L"Ask me anything about the app!";
            // 
            // askButton
            // 
            this->askButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->askButton->Location = System::Drawing::Point(815, 155);
            this->askButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->askButton->Name = L"askButton";
            this->askButton->Size = System::Drawing::Size(133, 49);
            this->askButton->TabIndex = 1;
            this->askButton->Text = L"Ask";
            this->askButton->UseVisualStyleBackColor = true;
            this->askButton->Click += gcnew System::EventHandler(this, &MyForm::askButton_Click);
            // 
            // showQuestionsButton
            // 
            this->showQuestionsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->showQuestionsButton->Location = System::Drawing::Point(513, 515);
            this->showQuestionsButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->showQuestionsButton->Name = L"showQuestionsButton";
            this->showQuestionsButton->Size = System::Drawing::Size(267, 49);
            this->showQuestionsButton->TabIndex = 4;
            this->showQuestionsButton->Text = L"Show Questions";
            this->showQuestionsButton->UseVisualStyleBackColor = true;
            this->showQuestionsButton->Click += gcnew System::EventHandler(this, &MyForm::showQuestionsButton_Click);
            // 
            // questionTextBox
            // 
            this->questionTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->questionTextBox->Location = System::Drawing::Point(358, 164);
            this->questionTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->questionTextBox->Name = L"questionTextBox";
            this->questionTextBox->Size = System::Drawing::Size(372, 30);
            this->questionTextBox->TabIndex = 2;
            // 
            // answerTextBox
            // 
            this->answerTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->answerTextBox->Location = System::Drawing::Point(373, 230);
            this->answerTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->answerTextBox->Multiline = true;
            this->answerTextBox->Name = L"answerTextBox";
            this->answerTextBox->ReadOnly = true;
            this->answerTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->answerTextBox->Size = System::Drawing::Size(532, 245);
            this->answerTextBox->TabIndex = 3;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1342, 654);
            this->Controls->Add(this->showQuestionsButton);
            this->Controls->Add(this->answerTextBox);
            this->Controls->Add(this->questionTextBox);
            this->Controls->Add(this->askButton);
            this->Controls->Add(this->chatbotMessageLabel);
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->Name = L"MyForm";
            this->Text = L"Chatbot Simulation";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        System::Void askButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ question = this->questionTextBox->Text;
            String^ answer = GetAnswer(question);
            this->answerTextBox->Text = answer;
        }

        System::Void showQuestionsButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            QuestionsForm^ questionsForm = gcnew QuestionsForm();
            questionsForm->ShowDialog();
        }

        String^ GetAnswer(String^ question)
        {
            // Dictionary of questions and answers
            System::Collections::Generic::Dictionary<String^, String^>^ qa = gcnew System::Collections::Generic::Dictionary<String^, String^>();

            // User Experience and Interface
            qa->Add("What key features should be included in the main dashboard of the application?", "The main dashboard should include features like a summary of recent activity, shortcuts to key functions, notifications, and user profile information.");
            qa->Add("How can the application be designed to be user-friendly for both tech-savvy and non-tech-savvy mothers?", "The application should have a simple and intuitive interface, clear instructions, and easy navigation. Using icons and step-by-step guides can help non-tech-savvy users.");
            qa->Add("What color schemes and design elements would appeal to mothers and children?", "Soft pastel colors, friendly and approachable fonts, and playful design elements can appeal to both mothers and children.");
            qa->Add("How can the app provide easy navigation and accessibility for its users?", "The app should have a clear layout, accessible menus, and support for voice commands and screen readers.");
            qa->Add("What age-specific content should be available for children within the app?", "The app should include educational games, stories, and videos tailored to different age groups, from toddlers to pre-teens.");

            // Health and Wellness
            qa->Add("What kind of health tracking features would be beneficial for mothers and their children?", "Features like growth tracking, vaccination schedules, symptom checkers, and health journals would be beneficial.");
            qa->Add("How can the app integrate with wearable devices to monitor the health metrics of mothers and children?", "The app can connect to wearable devices via Bluetooth to track metrics like steps, sleep patterns, heart rate, and activity levels.");
            qa->Add("What type of reminders and alerts could help mothers manage their children’s health appointments and medication schedules?", "The app can provide reminders for doctor appointments, vaccination dates, and medication times, with customizable alert settings.");
            qa->Add("How can the app provide personalized health tips and advice for different age groups?", "Using the user's input on age and health status, the app can offer tailored advice, health tips, and resources for different age groups.");
            qa->Add("What partnerships with healthcare providers or pediatricians could enhance the app’s value?", "Partnerships with healthcare providers can offer direct appointment scheduling, telehealth services, and access to verified health information.");

            // Education and Development
            qa->Add("What educational content should be included to support the development of children?", "The app should include interactive learning modules, educational games, age-appropriate videos, and reading materials.");
            qa->Add("How can the app encourage and track educational milestones and achievements?", "The app can provide progress tracking, rewards, and certificates for achieving educational milestones.");
            qa->Add("What features can help mothers find and enroll their children in local educational programs and activities?", "The app can include a directory of local educational programs, events, and activities with enrollment options.");
            qa->Add("How can the app provide resources for mothers to support their children’s learning at home?", "The app can offer tutorials, tips, and printable materials to help mothers engage with their children's education.");
            qa->Add("What tools can the app offer to monitor and manage screen time effectively?", "The app can provide screen time monitoring, usage reports, and parental controls to limit and manage screen time.");

            // Community and Support
            qa->Add("How can the app facilitate a community of mothers for sharing tips, advice, and support?", "The app can include forums, chat groups, and Q&A sections where mothers can interact and share experiences.");
            qa->Add("What types of forums or discussion boards would be valuable for mothers to connect?", "Discussion boards on topics like parenting tips, health advice, and educational resources can be valuable.");
            qa->Add("How can the app offer access to professional advice from pediatricians, child psychologists, and other experts?", "The app can feature live chat or Q&A sessions with experts and a repository of expert articles and videos.");
            qa->Add("What event planning or coordination features could help mothers organize playdates and group activities?", "The app can include event planning tools, calendars, and RSVPs for organizing and managing group activities.");
            qa->Add("How can the app include mental health resources and support for mothers?", "The app can offer resources like articles, relaxation techniques, counseling services, and peer support groups for mental health.");

            // Safety and Privacy
            qa->Add("What measures should be taken to ensure the safety and privacy of the users’ data?", "The app should use encryption, secure login methods, and comply with data protection regulations.");
            qa->Add("How can the app verify the identity of users to create a secure community?", "The app can use verification methods like email confirmation, phone verification, and identity checks.");
            qa->Add("What parental controls should be available to protect children’s information and usage?", "The app can provide parental controls to restrict content, monitor usage, and protect personal information.");
            qa->Add("How can the app provide emergency contact features for quick access to help when needed?", "The app can have an emergency contact button, quick dial features, and location sharing for emergencies.");
            qa->Add("What guidelines should the app follow to comply with data protection regulations?", "The app should follow GDPR, COPPA, and other relevant data protection regulations to ensure user privacy and security.");

            // Activities and Entertainment
            qa->Add("What kind of activities and games can the app include to entertain and educate children?", "The app can feature interactive games, puzzles, educational videos, and DIY activities.");
            qa->Add("How can the app offer suggestions for age-appropriate activities based on the child’s development stage?", "The app can use age inputs to recommend suitable activities and games for different development stages.");
            qa->Add("What features can help mothers find local family-friendly events and activities?", "The app can include a calendar of local events, filters for family-friendly activities, and maps for locations.");
            qa->Add("How can the app incorporate multimedia content like stories, songs, and videos for children?", "The app can have a library of multimedia content with stories, songs, and videos categorized by age and interest.");
            qa->Add("What types of interactive content can engage children while supporting learning?", "Interactive content like quizzes, story-based games, and virtual experiments can engage children and support learning.");

            // Feedback and Improvement
            qa->Add("What feedback mechanisms should be implemented to continuously improve the app?", "The app should have in-app surveys, feedback forms, and ratings to gather user opinions and suggestions.");
            qa->Add("How can the app gather insights on user satisfaction and areas for improvement?", "The app can use analytics, user feedback, and periodic reviews to understand satisfaction levels and improvement areas.");
            qa->Add("What features could encourage users to provide regular feedback?", "The app can incentivize feedback through rewards, badges, or premium features access for active contributors.");
            qa->Add("How can the app track usage patterns to identify popular features and potential issues?", "The app can use built-in analytics to monitor usage patterns, feature popularity, and identify any issues.");
            qa->Add("What strategies can be employed to keep the app updated with the latest content and features?", "Regular updates, user feedback integration, and staying informed about industry trends can help keep the app relevant.");

            // Provide the answer based on the question
            if (qa->ContainsKey(question))
            {
                return qa[question];
            }
            else
            {
                return "Sorry, I don't have an answer for that question.";
            }
        }
    };
}
