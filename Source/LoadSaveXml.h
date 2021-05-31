/*
  ==============================================================================
    LoadSaveXml.h
    Created: 6 Apr 2021 2:56:45pm
    Author:  deckard
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LoadSaveXml  : public juce::Component
{
public:
    LoadSaveXml();
    ~LoadSaveXml() override;

    String printNodeOne;
    String printNodeOnePath;

    void saveDuration(String timeInFull);

    void writeData(String currentPath);
    void loadData();

    juce::File returnFilePath();

//    String returnFilePath();

private:


    String newString = "YeahYeah";

    
   // const String outputNameofFile;

    String outputNameofFile;

    const String copyFile;

    void findXmlPath();





    // void counterFunc();

   static int counter;

   
    static int counterB;
//    int counter = 0;

    int numTries=0;


    // FILE * myxmlfile;
    // FILE * dir;

    juce::File myxmlfilecopy;
    juce::File siblingFile;


    juce::File myxmlfile;
    juce::File dir;


      // getFirstChildElement
       juce::XmlElement* nodeOne;
       juce::XmlElement* nodeTwo;
       juce::XmlElement* nodeThree;
       juce::XmlElement* nodeFour;
//statement

    
    std::shared_ptr<juce::XmlElement> xmlMadeThing;


    String printNodeTwo;
    String printNodeThree; // I think printNodeThree maybe destroyed once the scope ends. 
    String printNodeFour; 

    String newTimeInFull;





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoadSaveXml)
};