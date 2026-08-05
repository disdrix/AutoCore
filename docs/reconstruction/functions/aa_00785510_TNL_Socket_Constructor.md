# Function record: TNL_Socket_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00785510` |
| **Canonical name** | `TNL_Socket_Constructor` |
| **Ghidra / plate** | `TNL_Socket_Constructor` / `"Socket::Socket"` |
| **Address** | `0x00785510` |
| **Body span** | `0x00785510` – `0x00785c0d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | network-tnl-socket |
| **Completion status** | **partial** — three-rep + dual A/B 2026-07-29; Address/TCP-aux/journal English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | **Present** — accept-with-gaps |

## Alias

- Scaffold / legacy: `FUN_00785510`, `Named_Socket_Socket`
- Coverage inventory: `TNL_Socket_Constructor`

## Purpose

Construct a TNL `Socket`: create Winsock handle for UDP/TCP/IPX, bind to `Address`, set recv/send buffer sizes, optional broadcast (non-TCP), non-blocking IO, optional TCP `listen(5)`, plus journal record/playback of the OS handle.

## Signature (OWN body sealed)

```c
/* __stdcall — ret 0x18; returns this in EAX */
Socket * TNL_Socket_Constructor(
    Socket *self,              /* +0 handle, +4 type, +8/+0xc TCP aux */
    unsigned short *address,   /* TNL Address*: type @0; [1] TCP listen gate */
    unsigned int sendBufferSize,   /* SO_SNDBUF 0x1001 */
    unsigned int recvBufferSize,   /* SO_RCVBUF 0x1002 */
    unsigned int allowBroadcast,   /* SO_BROADCAST 0x20; skipped if type==TCP */
    unsigned char nonBlocking      /* FIONBIO 0x8004667E */
);
```

## Transport map

| type | socket() | name VA | string |
|---:|---|---:|---|
| 0 | `(2,2,0)` AF_INET/SOCK_DGRAM | `0x00a9b188` | UDP |
| 1 | `(2,1,0)` AF_INET/SOCK_STREAM + two `new(0x18)` aux | `0x00a9b184` | TCP |
| 2 | `(6,2,1000)` AF_IPX/SOCK_DGRAM/NSPROTO_IPX | `0x00a9b180` | IPX |

## Callers (xrefs)

| Address | Function | Notes |
|---|---|---|
| `0x0042c070` | `FUN_0042c010` | `Socket` at `this+0x1a`; buf `0x8000/0x8000`; broadcast+nonblock `1,1` |
| `0x0042d4ae` | `FUN_0042d440` | heap Socket; buf `1000000/1000000`; `1,1` |

## Notable callees (not owned this dual)

| VA / import | Role (inferred) |
|---|---|
| `socket` / `bind` / `getsockname` / `setsockopt` / `ioctlsocket` / `listen` / `closesocket` | Winsock |
| `htonl` | addr helpers |
| `FUN_00784560` | pre-create setup |
| `FUN_00784490` | Address → sockaddr |
| `FUN_007843e0` | sockaddr → Address |
| `FUN_007845c0` | Address → log string |
| `FUN_00783ee0` | TCP aux object ctor (0x18) |
| `FUN_00783b60` / `FUN_00783aa0` | LogUDP get/print |
| `BitStream_readBits` / `BitStream_writeBits` | journal handle I/O |
| `FUN_007803f0` / `FUN_00780060` | journal stamp / flush residual |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00785510_FUN_00785510.md`
- Annotated: `docs/reconstruction/raw/aa_00785510_FUN_00785510.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TNL_Socket_Constructor.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00785510_TNL_Socket_Constructor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00785510_TNL_Socket_Constructor.md`
- Legacy clean alias: `docs/reconstruction/reconstructed-exact/FUN_00785510.cpp`, `Named_Socket_Socket.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | **High** |
| stdcall 6-arg ABI + return this | **High** |
| UDP/TCP/IPX + SO_* / FIONBIO map | **High** |
| Address field English beyond type | **Probable / open** |
| TCP aux product type | **Tentative** |
| AutoCore full port | **Gap** (UDP-only wrapper) |
