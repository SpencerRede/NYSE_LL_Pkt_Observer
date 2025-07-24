# NYSE_LL_Pkt_Observer

### Build Instructions:
- cd build
- cmake ..
- cmake --build .

#### To run:
./pcap_relay _{path to pcap file to read}_

## PCAP Replay (PCAP_Server: Reader & Server)
PCAP_Server reads a `.pcap` file containing network packets (e.g., NYSE feed captures) and serves them in real time over a UDP socket to `127.0.0.1:5000`, replaying packets at their original capture timestamps to simulate live feed data. It allows:

- Parsing `.pcap` files and extracting packets and timing information using `libpcap`.
- Serving packets on a local UDP socket for integration testing of low-latency ingestion pipelines.
- Non-blocking design allowing the main thread to execute other tasks while packets are replayed.

## Socket Observer (Pkt_Observer: RingBuffer & Ring_Buff_Forwarder)
`PacketBufferForwarder` listens on a UDP socket (127.0.0.1:5000 by default) for NYSE packet streams (e.g., from PCAP_Server or live multicast feeds) and forwards packets into a RingBuffer for decoupled processing. It allows:

- Non-blocking ingestion of UDP packets: separating network I/O from CPU-heavy parsing and processing tasks.
- Handling burst traffic gracefully: buffering incoming packets temporarily during spikes to prevent drops when the parser is slower than the network arrival rate.
- Decoupled producer-consumer architecture: `PacketBufferForwarder` focuses on receiving packets rapidly while an Observer focuses on parsing NYSE Pillar feed packets at its own pace.
- Modular testing: enabling the replacement of the network feed with test producers to validate parsing and processing logic without requiring live or replayed network traffic.

## TODO:
- Build Observer.cpp to reinterpret cast packets into cooresponding structs, collecting metrics and storing information in respective Symbol / Order Registry
- Add logic for Add Order, Modify Order, Delete Order and Replace Order to build an order book

- Create Symbol Registry to store metadata on each symbol, unordered_map indexed by null-terminated index symbol
    - Tracking market_state, last published prices, respective id's, exchange code, etc.
    - Handles Msg Codes 3 (IndexMap), 32 (Symbol Clear), and 34 (Update Symbol Status)

- Create Order book, unordered_map indexed by orderID and storing price, volume, and side (Buy / Sell)
    - Track Metrics -> Total # of orders, Total vol of orders executed, and count of each individual order (Buy, Sell, delete, replaces, executed)

- Optional: Packet Level metrics (# of total packets, retransmissions, refreshes, and unavailible packets)
