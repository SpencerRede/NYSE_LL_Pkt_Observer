#pragma once
#include <vector>
#include <cstdint>
#include <sys/time.h>

namespace MessageData {

    #pragma pack(push, 1)

    /*
    Pkt Header Delivery Flag:
        A flag that indicates whether this is an original,
        retransmitted, or ‘replayed’ message. Valid
        values include:
        ▪ 1 – Heartbeat
        ▪ 10 – Failover (see Publisher Failover)
        ▪ 11 – Original Message
        ▪ 12 – Sequence Number Reset Message
        ▪ 13 – Only one packet in retransmission
        sequence
        ▪ 15 – Part of a retransmission sequence
        ▪ 17 – Only one packet in Refresh sequence
        ▪ 18 – Start of Refresh sequence
        ▪ 19 – Part of a Refresh sequence
        ▪ 20 – End of Refresh sequence
        ▪ 21 – Message Unavailable
    */
    struct NYSEPacketHeader {
        uint16_t PktSize;
        uint8_t DeliveryFlag;
        uint8_t NumberMsgs;
        uint32_t SeqNum;
        uint32_t SendTime;
        uint32_t SendTimeNS;
    };

    struct NYSEMsgHeader {
        uint16_t MsgSize;
        uint16_t MsgType;
    };

    // Message specific structs
    struct NYSESeqNumRst {
        uint16_t MsgSize;
        uint16_t MsgType;             //      MsgType 1
        uint32_t SourceTime;
        uint32_t SourceTimeNS;
        uint8_t ProductID;
        uint8_t ChannelID;
    };

    struct NYSESrcTimeRef {
        uint16_t MsgSize;
        uint16_t MsgType;             //      MsgType 2
        uint32_t ID;    
        uint32_t SymbolSeqNum;
        uint32_t SourceTimeS;
    };

    /*
    This message is published over the real-time data channels at system startup or in the context of a refresh sequence
    after a Matching Engine or Pillar Publisher failover. It provides referential data for a single specified symbol.
    */
    struct NYSEIndexMap {
        uint16_t MsgSize;             // 0
        uint16_t MsgType;             // 2    MsgType 3
        uint32_t SymbolIndex;         // 4
        char Symbol[11];              // 8 (null-terminated, null-padded)
        uint8_t Reserved;             // 19
        uint16_t MarketID;            // 20
        uint8_t SystemID;             // 22
        char ExchangeCode;            // 23
        uint8_t PriceScaleCode;       // 24
        char SecurityType;            // 25
        uint16_t LotSize;             // 26
        uint32_t PrevClosePrice;      // 28
        uint32_t PrevCloseVolume;     // 32
        uint8_t PriceResolution;      // 36
        char RoundLot;                // 37
        uint16_t MPV;                 // 38
        uint16_t UnitOfTrade;         // 40
        uint16_t Reserved2;           // 42
    };

    /*
    The client should react to receipt of a Symbol Clear message by clearing all state 
    information for the specified symbol in anticipation of receiving a full state refresh.
    */
    struct NYSESymClear {
        uint16_t MsgSize;
        uint16_t MsgType;              //       MsgType 32
        uint32_t SourceTimeS;
        uint32_t SourceTimeNS;
        uint32_t SybolIndex;
        uint32_t NextSourceSeqNum;
    };

    /*
    This message informs clients of changes in the status of a specific security, such as Trading Halts, Short Sale Restriction
    state changes, etc. Security Status of “B” is published once the Pillar Gateways begin accepting orders on a given
    market, e.g. NYSE Arca Pillar publisher data feeds will publish this security status at 2:30am ET, but the MarketState
    field will still reflect Pre-Opening.
    */
    struct NYSESymStatus {
        uint16_t MsgSize;             // 0
        uint16_t MsgType;             // 2      MsgType 34
        uint32_t SourceTime;          // 4
        uint32_t SourceTimeNS;        // 8
        uint32_t SymbolIndex;         // 12
        uint32_t SymbolSeqNum;        // 16
        char SecurityStatus;          // 20
        char HaltCondition;           // 21
        uint32_t Reserved;            // 22
        uint32_t Price1;              // 26
        uint32_t Price2;              // 30
        char SSRTriggeringExchangeID; // 34
        uint32_t SSRTriggeringVolume; // 35
        uint32_t Time;                // 39 (HHMMSSmmm)
        char SSRState;                // 43
        char MarketState;             // 44
        char SessionState;            // 45
    };

    #pragma pack(pop)
} // namespace PCAPServer