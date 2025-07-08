# NYSE_LL_Pkt_Observer

### Build Instructions:
- cd build
- cmake ..
- cmake --build .

#### To run:
./pcap_relay _{path to pcap file to read}_

## PCAP Replay
PCAP_Server reads a `.pcap` file containing network packets (e.g., NYSE feed captures) and serves them in real time over a UDP socket to `127.0.0.1:5000`, replaying packets at their original capture timestamps to simulate live feed data. It allows:

- Parsing `.pcap` files and extracting packets and timing information using `libpcap`.
- Serving packets on a local UDP socket for integration testing of low-latency ingestion pipelines.
- Non-blocking design allowing the main thread to execute other tasks while packets are replayed.
