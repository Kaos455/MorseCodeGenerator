/* New Plan for Events 
My old understanding of Event Systems was off, with the help of online articles such as https://symfony.com/doc/current/components/event_dispatcher.html and https://docs.oracle.com/javase/8/javafx/api/javafx/event/EventDispatcher.html
and ChatGPT for consolidating understanding. Whilst not being same language the same principle applies.

The Principle:
An Event Listener chain which runs different processes troughout the application to build the proper functionality.

How to do it?
EventDispatcher - Main Class
std::unordered_map - A map to store the associated Events and listeners to run along with them.
std::function<void()> - A part of the Functional header to store a function (An event listener) in a vector.

Problems:
Removing a listener from the vector. This is due to how std::function does not have a boolean operator (==)

Current Idea:
Having a structure that holds an ID and checking the ID instead of the function signature.

this will look like ->
struct Listener { int id; std::function<void()> function; };
where ID will just be a simple Incremental operation per function added starting from 0.
Looking into vector methods I found a std::find_if function with the help of ChatGPT which can be used with a Lambda expression to find the correct ID using a boolean operation operation.

Issues with EventDispatcher:
With added complexity the Event Chain may become convoluted and hard to understand, So in the future if more features are added may need to think of a better way of doing it. My Idea with this would be to split the event chains into subchains with specific
goals, like making "reusable" code with Events. 
*/