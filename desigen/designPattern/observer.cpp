#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() = default;  // virtual destructor for interface
};
    
// Abstract Observable interface: a YouTube channel interface
class IChannel {
public:
    virtual void subscribe(shared_ptr<ISubscriber> subscriber) = 0;
    virtual void unsubscribe(shared_ptr<ISubscriber> subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual void uploadVideo(const string& title)=0;
    virtual string getVideoData()=0;
    virtual ~IChannel() =default ;
};

// Concrete Subject: a YouTube channel that observers can subscribe to
class Channel : public IChannel {
private:
    vector<shared_ptr<ISubscriber>> subscribers;  // list of subscribers
    string channelName;
    string latestVideo;               // latest uploaded video title
public:
    Channel(const string& name) {
        this->channelName = name;
    }

    // Add a subscriber (avoid duplicates)
    void subscribe(shared_ptr<ISubscriber> subscriber) {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    // Remove a subscriber if present
    void unsubscribe(shared_ptr<ISubscriber> subscriber) {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    // Notify all subscribers of the latest video
    void notifySubscribers() override {
        for (auto& sub : subscribers) {
            sub->update();
        }
    }

    // Upload a new video and notify all subscribers
    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << channelName << " uploaded \"" << title << "\"]\n";
        notifySubscribers();
    }

    // Read video data
    string getVideoData() {
        return "\nCheckout our new Video : " + latestVideo + "\n";
    }
};

// Concrete Observer: represents a subscriber to the channel
class Subscriber : public ISubscriber {
private:
    string name;
    shared_ptr<IChannel> channel;
public:
    Subscriber(const string& name, shared_ptr<IChannel> channel) {
        this->name = name;
        this->channel = channel;
    }

    // Called by Channel; prints notification message
    void update() override {
        // No need for downcast, use IChannel interface
        cout << "Hey " << name << "," << channel->getVideoData();
    }
};

int main() {
    // Create a channel and subscribers
    shared_ptr<IChannel> channel = make_shared<Channel>("CoderArmy");

    auto subs1 = make_shared<Subscriber>("Varun", channel);
    auto subs2 = make_shared<Subscriber>("Tarun", channel);

    // Varun and Tarun subscribe to CoderArmy
    channel->subscribe(subs1);
    channel->subscribe(subs2);

    // Upload a video: both Varun and Tarun are notified
    channel->uploadVideo("Observer Pattern Tutorial");

    // Varun unsubscribes; Tarun remains subscribed
    channel->unsubscribe(subs1);

    // Upload another video: only Tarun is notified
    channel->uploadVideo("Decorator Pattern Tutorial");

    return 0;
}