- loadData is being fired twice! And I need to find the logic and understand it and show how it works, possibly with output statements. 


# ManyVoxV1

I'm adding this functionality to this app which is:  https://gist.github.com/dchavours/2ea06638c3a3084f4a625f92c5ad74c4


^^^^^^^^^^^^^^^^^^^^^^^^

Just add the TableBoxTutorial and have it be visible then,


I'm adding the TableListBoxTutorial logic to be opened and closed based upon the Toggle View Click. 


TableListBoxTutorial -> https://docs.juce.com/master/tutorial_table_list_box.html


Looking into this block of code for changing visibility of a window. 


```

class MainWindow : public Component
{
public:
    MainWindow()
    {
        addAndMakeVisible (openWindow);
        openWindow.onClick = [&]
        {
            if (window)
                window->bringToFront();
            else
            {
                window = new TopLevelWindow();
                window->addToDesktop ();
                window->centreWithSize (600, 400);
                window->setVisible (true);
            }
    }
    ~MainWindow()
    {
        // there are probably nicer ways using RAII, but this copes with the window being closed and destroyed
        if (window)
            delete window;
    }

    void resized() override
    {
        openWindow.setBounds (10, 10, 70, 25);
    }
private:
    TextButton openWindow { {}, "Window" };
    Component::SafePointer<TopLevelWindow> window;
};



```


If you compiled this it would look like =>  https://imgur.com/a/yUPDsTs

The current function of ManyVox is to summarize vocal stems and use algorithms to reduce volume and avoid the automating of knob movement normally found 
on the channel mixer. 

Thus, reducing the need for compression as well as reducing the amount of time and effort spent on adjusting the volume of a certain vocal stem track.


