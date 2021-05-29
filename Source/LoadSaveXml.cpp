/*
  ==============================================================================
    LoadSaveXml.cpp
    Created: 6 Apr 2021 2:56:45pm
    Author:  deckard
  ==============================================================================
*/

#include <JuceHeader.h>
#include "LoadSaveXml.h"
#include "MainComponent.h"


//==============================================================================
LoadSaveXml::LoadSaveXml()
{


    loadData();

  

}

LoadSaveXml::~LoadSaveXml()
{
}


void LoadSaveXml::saveDuration(String timeInFull){

    std::cout << "Time in full: " << timeInFull << std::endl;

    newTimeInFull = timeInFull;


}



int LoadSaveXml::counterB=0;
void LoadSaveXml::loadData(){
  // A preamble to queue all files. 
       // Uncomment this out again to figure out
       // when loadData is being called.
       counterB++;
        std::cout << "counterB: " << counterB << std::endl;

            if(!myxmlfile.exists()){

            // I think this stays because its static.
            dir = juce::File::getCurrentWorkingDirectory();


            while (! dir.getChildFile ("Resources").exists() && numTries++ < 15)
                dir = dir.getParentDirectory();


            myxmlfile = dir.getChildFile ("Resources").getChildFile ("FilePaths.xml");

            }



              if (myxmlfile.exists()) {

            std::cout << "myxmlfile.exists() "<< std::endl;

            outputNameofFile = myxmlfile.getFullPathName();

            copyFile = outputNameofFile;
            //outputNameofFile = myxmlfile.getFullPathName();
            std::cout << outputNameofFile << std::endl;


            siblingFile = myxmlfile.getSiblingFile("TableData");


                    if(!siblingFile.exists()){

                        std::cout << "siblingFile does not exist to begin with" << std::endl;

                    }

            xmlMadeThing = juce::XmlDocument::parse(myxmlfile);

     
            if (xmlMadeThing->hasTagName("NODES"))
            {
                // Checking to see if the file exist and is reading the tags.
                // What if I get relative path from and save it? 
                Logger::outputDebugString("Statement 6, The xml file does have that tag name.");


                // Reading the xml string. 

              nodeOne = xmlMadeThing->getFirstChildElement();

              printNodeOnePath = nodeOne->getStringAttribute("PATH");
              std::cout << "printNodeOnePath: " << printNodeOnePath << std::endl;

              
              printNodeOne = "printNodeOne";


              std::cout << newTimeInFull << std::endl;
    
          }

      }

         std::cout << "loadData has been fired: " << counterB << " times" << std::endl;

}





void LoadSaveXml::writeData(String currentPath){


         std::cout << outputNameofFile << std::endl;


              if(siblingFile.exists()){

              std::cout << "_" << std::endl;  


              }

              if(!siblingFile.exists()){

              std::cout << "!" << std::endl;  


              }


              // I still need to replace the below line with a better file path.

//            auto directDirTwo = juce::File("../Resources/FilePaths.xml");




                        
          //   auto directDir = juce::File::getCurrentWorkingDirectory();


          //    auto directDirTwo = juce::File("/home/deck/Documents/ManyVoxV1-e5ad740841934c1522db7b637c4ef5d6e598760e/Resources/FilePaths.xml");
             
          //     if (directDir.isDirectory()){

          //     std::cout << "directDir" << std::endl;  

          //     auto directDirNumber = directDirTwo.getNumberOfChildFiles( 2, "*.xml");

          //     std::cout << directDirNumber << std::endl;  

          //     auto outputNameofFileTwo = directDirTwo.getFullPathName();




          //     }

          //     if (!directDir.isDirectory()){

          //     std::cout << "!directDir" << std::endl;  

          //     }

          //     std::cout << "writeData()" << std::endl;  
                       


          // if (newTimeInFull.isNotEmpty()){

          //     if(directDir.exists()){

          //       if (directDir.hasWriteAccess()){

          //           xmlMadeThing = juce::XmlDocument::parse(directDir);

          //           nodeOne = xmlMadeThing->getFirstChildElement();

          //           printNodeOne = nodeOne->getAllSubText();

                  
          //         // Lets see if nodeOne is the problem.
          //        std::cout << "printNodeOne is: " << printNodeOne << std::endl;  
 
          //         std::cout << "About to set Attribute" << std::endl;  
                  


          //         nodeOne->setAttribute ("DURATION", newTimeInFull);
          //         nodeOne->setAttribute ("PATH", currentPath);


          //         std::cout << "About to write" << std::endl;  
          //         xmlMadeThing->writeTo(directDir, XmlElement::TextFormat());
          //   }
          //   }
          // }
          


          // if (newTimeInFull.isEmpty()){

            
          // }





          //=====================================================


          //  nodeOne->setAttribute ("ID", newTimeInFull);
          // xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());



        }
    

