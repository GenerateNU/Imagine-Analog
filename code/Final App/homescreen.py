import kivy
kivy.require('2.1.0')

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty
from kivy.lang import Builder
from kivy.core.window import Window
from kivy.config import Config
from kivy.uix.button import Button
from kivy.uix.image import Image, AsyncImage 
from kivy.uix.screenmanager import ScreenManager, Screen


#Define our different screens
class HomeScreen(Screen):
    pass

class SettingsScreen(Screen): 
    pass

class WindowManager(ScreenManager):
    pass

kv = Builder.load_file('windowmanager.kv')

#class MyLayout(Widget):
#    pass


class AwesomeApp(App):
    def build(self):
        Window.size = (400, 240)
        Window.clearcolor = (0,0,0,1)
        return kv

if __name__ == '__main__':
    AwesomeApp().run()