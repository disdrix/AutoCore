// =============================================================================
// TNL_Socket_Constructor  (TNL Socket::Socket)
// -----------------------------------------------------------------------------
// Stable ID: aa_00785510
// Address:   0x00785510  (autoassault.exe, image base 0x400000)
// Body:      0x00785510 – 0x00785c0d
// System:    network-tnl-socket
// Generated: 2026-07-29 dual A/B strengthen (from live Ghidra decompile)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_00785510_TNL_Socket_Constructor.md
//            reviews/B_aa_00785510_TNL_Socket_Constructor.md
// =============================================================================
//
// PURPOSE:
//   Construct TNL Socket: create Winsock handle (UDP/TCP/IPX), bind Address,
//   set SO_RCVBUF / SO_SNDBUF, optional SO_BROADCAST (non-TCP), FIONBIO,
//   optional TCP listen(5), journal record/playback of OS handle.
//
// ABI (sealed OWN body):
//   __stdcall, 6 stack args, returns this (EAX). Epilogue: ret 0x18.
//
// Layout (written here):
//   +0x00 SOCKET handle
//   +0x04 U32 transport (0=UDP, 1=TCP, 2=IPX)
//   +0x08 / +0x0c TCP aux objects (0x18 each) or 0
//
// Transport name table @ 0x00a9b180: "IPX", "TCP", "UDP"
// FIONBIO = 0x8004667E
// =============================================================================

#include <cstdint>

// Winsock / CRT imports (names for readability; retail uses IAT).
extern "C" {
  using SOCKET = std::uint32_t;
  constexpr SOCKET INVALID_SOCKET = 0xFFFFFFFFu;
  constexpr int AF_INET = 2;
  constexpr int AF_IPX = 6;
  constexpr int SOCK_STREAM = 1;
  constexpr int SOCK_DGRAM = 2;
  constexpr int NSPROTO_IPX = 1000;
  constexpr int SOL_SOCKET = 0xFFFF;
  constexpr int SO_SNDBUF = 0x1001;
  constexpr int SO_RCVBUF = 0x1002;
  constexpr int SO_BROADCAST = 0x20;
  constexpr long FIONBIO = 0x8004667EL;

  SOCKET __stdcall socket(int af, int type, int protocol);
  int __stdcall bind(SOCKET s, const void *addr, int namelen);
  int __stdcall getsockname(SOCKET s, void *addr, int *namelen);
  int __stdcall setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen);
  int __stdcall ioctlsocket(SOCKET s, long cmd, unsigned long *argp);
  int __stdcall listen(SOCKET s, int backlog);
  int __stdcall closesocket(SOCKET s);
  unsigned long __stdcall htonl(unsigned long hostlong);
  void *operator_new(unsigned size);
  void BitStream_readBits(int bitCount, void *out);
  void BitStream_writeBits(int bitCount, void *in);
}

// Residuals (not dual-owned this unit).
void FUN_00784560();
void FUN_00784490();          // Address → sockaddr (args elided in decompiler)
void FUN_007843e0();          // sockaddr → Address
void *FUN_007845c0();         // Address → log string
std::uint32_t FUN_00783ee0(); // TCP aux ctor (this = operator_new(0x18) block)
void *FUN_00783b60(const char *channel);
void FUN_00783aa0(const char *fmt, ...);
void FUN_007803f0(void *stamp);
void FUN_00780060();

// Journal / log globals (addresses from decompile).
extern int DAT_00d179e4;           // 1=record, 2=playback (product English residual)
extern char DAT_00d179e0;          // journal enable
extern int DAT_00d179fc;
extern int DAT_00d179f8;
extern char DAT_00afddd4;
extern int DAT_00afddd0;
extern int DAT_00d179e8;
extern void *DAT_00d17a00;
extern int _DAT_00d208a4;          // one-time init bitmask for log stamps
// ... per-channel LogUDP slots DAT_00d208* omitted for brevity in clean port map

extern char DAT_00a9b180[]; // "IPX"
extern char DAT_00a9b184[]; // "TCP"
extern char DAT_00a9b188[]; // "UDP"

struct TNL_Socket {
  SOCKET handle;            // +0x00
  std::uint32_t transport;  // +0x04  0=UDP 1=TCP 2=IPX
  void *tcpAuxA;            // +0x08
  void *tcpAuxB;            // +0x0c
};

// Local stand-in so clean is self-describing (not linked).
struct sockaddr_storage_placeholder {
  char bytes[0x10];
};

// Decompiler: SOCKET * TNL_Socket_Constructor(SOCKET *param_1, ushort *param_2,
//   undefined4 param_3, undefined4 param_4, SOCKET param_5, byte param_6)
TNL_Socket *__stdcall TNL_Socket_Constructor(
    TNL_Socket *self,
    unsigned short *address,       // TNL Address* (type @0; [1] listen gate)
    unsigned int sendBufferSize,   // param_3 → SO_SNDBUF
    unsigned int recvBufferSize,   // param_4 → SO_RCVBUF
    unsigned int allowBroadcast,   // param_5
    unsigned char nonBlocking)     // param_6
{
  TNL_Socket *const th = self;
  th->tcpAuxA = nullptr;
  th->tcpAuxB = nullptr;

  // --- Journal playback (mode == 2) ---
  if (DAT_00d179e4 == 2 && DAT_00d179e0 != 0) {
    // stamp "Socket::Socket" (one-time bitmask path omitted)
    FUN_007803f0(/* &DAT_00d20898 stamp */);
    DAT_00d179fc = DAT_00d179fc + 1;
    if (DAT_00d179f8 != 0 && DAT_00d179f8 <= DAT_00d179fc) {
      __debugbreak();
      return th;
    }
    BitStream_readBits(0x20, &allowBroadcast); // reuses stack slot as handle temp
    th->handle = allowBroadcast;
    if (DAT_00afddd4 == 0 && DAT_00afddd0 < DAT_00d179e8)
      return th;
    __debugbreak();
    return th;
  }

  FUN_00784560();
  th->handle = INVALID_SOCKET;
  th->transport = static_cast<std::uint32_t>(address[0]);

  const char *typeName = DAT_00a9b188; // "UDP" default for logs
  const unsigned short type = address[0];

  if (type == 0) {
    th->handle = socket(AF_INET, SOCK_DGRAM, 0);
  } else if (type == 1) {
    typeName = DAT_00a9b184; // "TCP"
    th->handle = socket(AF_INET, SOCK_STREAM, 0);
    void *a = operator_new(0x18);
    th->tcpAuxA = a ? reinterpret_cast<void *>(FUN_00783ee0()) : nullptr;
    void *b = operator_new(0x18);
    th->tcpAuxB = b ? reinterpret_cast<void *>(FUN_00783ee0()) : nullptr;
  } else if (type == 2) {
    typeName = DAT_00a9b180; // "IPX"
    th->handle = socket(AF_IPX, SOCK_DGRAM, NSPROTO_IPX);
  } else {
    // LogUDP: "Attempted to create a socket bound to an invalid transport."
  }

  if (th->handle == INVALID_SOCKET)
    goto epilogue;

  // LogUDP: "%s socket created.", typeName
  {
    int namelen = 0x10;
    sockaddr_storage_placeholder local_24{};
    FUN_00784490(); // fills local_24 from Address
    int err = bind(th->handle, &local_24, namelen);

    // zeroed getname-related temps + htonl(0) present in retail body
    if (err == 0) {
      namelen = 0x10;
      getsockname(th->handle, &local_24, &namelen);
      FUN_007843e0();
      // LogUDP: "%s socket bound to address: %s", typeName, FUN_007845c0()
      err = setsockopt(th->handle, SOL_SOCKET, SO_RCVBUF,
                       reinterpret_cast<const char *>(&recvBufferSize), 4);
    } else {
      // LogUDP: unable to bind...
    }

    if (err == 0) {
      // LogUDP: receive buffer size set to recvBufferSize
      err = setsockopt(th->handle, SOL_SOCKET, SO_SNDBUF,
                       reinterpret_cast<const char *>(&sendBufferSize), 4);
    } else {
      // LogUDP: unable to set receive buffer...
    }

    if (err == 0) {
      // LogUDP: send buffer size set to ... (retail logs recvBufferSize — quirk)
      if (th->transport != 1) {
        unsigned int bc = allowBroadcast & 0xff;
        err = setsockopt(th->handle, SOL_SOCKET, SO_BROADCAST,
                         reinterpret_cast<const char *>(&bc), 4);
        goto check_broadcast_or_fail;
      }
      // TCP: skip broadcast; fall through to nonblock
    } else {
      // LogUDP: unable to set send buffer...
    check_broadcast_or_fail:
      if (err != 0) {
        // LogUDP: unable to set broadcast / init error
        closesocket(th->handle);
        th->handle = INVALID_SOCKET;
        goto epilogue;
      }
    }

    unsigned long nb = nonBlocking;
    ioctlsocket(th->handle, FIONBIO, &nb);
    // LogUDP: non-blocking IO set. Socket initialized.

    if (th->transport == 1 && address[1] != 0) {
      int lerr = listen(th->handle, 5);
      if (lerr != 0) {
        // LogUDP: "TCP Socket could not start listening: %s, %d." — no close
      }
    }
  }

epilogue:
  // --- Journal record (mode == 1) ---
  if (DAT_00d179e4 == 1 && DAT_00d179e0 != 0) {
    FUN_007803f0(/* &DAT_00d2085c stamp "Socket::Socket" */);
    allowBroadcast = th->handle;
    BitStream_writeBits(0x20, &allowBroadcast);
    FUN_00780060();
  }
  return th;
}
