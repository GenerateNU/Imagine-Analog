import kivy
kivy.require('2.1.0')

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty
from kivy.lang import Builder

Builder.load_file('whatever.kv')

class MyGridLayout(Widget):

    name = ObjectProperty(None)
    pizza = ObjectProperty(None)
    position = ObjectProperty(None)

    def press(self):
        name = self.name.text
        pizza = self.pizza.text
        position = self.position.text

        print(f"Hello {name}, you like {pizza} pizza, and your favorite position is {position}!")

        # Print to Screen
        #self.add_widget(Label(text=f"Hello {name}, you like {pizza} pizza, and your favorite position is {position}!"))

        # Clear the input boxes
        self.name.text = ""
        self.pizza.text = ""
        self.position.text = ""


class AwesomeApp(App):
    def build(self):
        return MyGridLayout()

if __name__ == '__main__':
    AwesomeApp().run()
