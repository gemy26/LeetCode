class Router {
private:
    class Packet {
    public:
        int source, destination, timestamp;
        Packet(int source, int destination, int timestamp) {
            this->source = source;
            this->destination = destination;
            this->timestamp = timestamp;
        }

        bool operator<(const Packet& other) const {
            if (destination != other.destination)
                return destination < other.destination;
            if (timestamp != other.timestamp)
                return timestamp < other.timestamp;
            return source < other.source;
        }
    };

public:
    deque<Packet> data;
    set<Packet> unique;
    map<int, deque<int>> sameDest;
    int limit;
    Router(int memoryLimit) { this->limit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        Packet packet(source, destination, timestamp);
        if (unique.count(packet)) {
            return false;
        }

        unique.insert(packet);
        data.push_back(packet);
        while (data.size() > this->limit) {
            auto deletedPacket = data.front();
            data.pop_front();
            unique.erase(deletedPacket);
            sameDest[deletedPacket.destination].pop_front();
        }

        sameDest[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        vector<int> nextPacket;
        if (data.size()) {
            Packet packet = data.front();
            data.pop_front();
            unique.erase(packet);
            nextPacket.push_back(packet.source);
            nextPacket.push_back(packet.destination);
            nextPacket.push_back(packet.timestamp);
            sameDest[packet.destination].pop_front();
        }
        return nextPacket;
    }

    int getCount(int destination, int startTime, int endTime) {

        // for(auto it : sameDest[destination]) cout << it << " ";
        // cout << endl;

        auto l = lower_bound(sameDest[destination].begin(),
                             sameDest[destination].end(), startTime);

        auto r = upper_bound(sameDest[destination].begin(),
                             sameDest[destination].end(), endTime);

         return (r - sameDest[destination].begin()) -
               (l - sameDest[destination].begin());

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */