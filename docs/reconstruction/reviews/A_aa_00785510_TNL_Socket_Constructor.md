# Review A (reconstruction fidelity): `aa_00785510` TNL_Socket_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00785510` |
| **VA** | `0x00785510` |
| **Body span** | `00785510` – `00785c0d` |
| **Canonical name** | `TNL_Socket_Constructor` |
| **Plate / journal name** | `Socket::Socket` |
| **System** | network-tnl-socket |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00785510_TNL_Socket_Constructor.md` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

TNL **`Socket::Socket` constructor** — create, bind, configure, and nonblock-enable a Winsock socket for a given **transport / bind address**, with optional TCP listen and journal record/playback hooks.

Stages (live decompile ≡ raw CF):

1. Zero `this+0x08` / `this+0x0c` (TCP aux slots).
2. **Playback journal** (`DAT_00d179e4 == 2` && `DAT_00d179e0`): stamp `"Socket::Socket"`, `BitStream_readBits(0x20)` into socket handle, early return (no real socket).
3. Else: `FUN_00784560()` (WSA/setup residual), set handle `INVALID_SOCKET` (`0xffffffff`), store transport type from `*address`.
4. **Transport create:**
   - type **0** → `socket(AF_INET=2, SOCK_DGRAM=2, 0)` — **UDP** (`"UDP"` @ `0x00a9b188`)
   - type **1** → `socket(AF_INET=2, SOCK_STREAM=1, 0)` — **TCP** (`"TCP"` @ `0x00a9b184`) + two `operator_new(0x18)` / `FUN_00783ee0` objects at `this+8` / `this+0xc`
   - type **2** → `socket(AF_IPX=6, SOCK_DGRAM=2, NSPROTO_IPX=1000)` — **IPX** (`"IPX"` @ `0x00a9b180`)
   - else → log `"Attempted to create a socket bound to an invalid transport."`
5. On valid handle: log created; `FUN_00784490` → `bind`; on success `getsockname` + `FUN_007843e0` (Address refresh residual).
6. `setsockopt(SOL_SOCKET, SO_RCVBUF=0x1002, recvBuf)`; then `SO_SNDBUF=0x1001, sendBuf`.
7. If transport **≠ TCP**: `setsockopt(SOL_SOCKET, SO_BROADCAST=0x20, allowBroadcast)`.
8. On any of bind/RCV/SND/broadcast failure chain: close + invalidate handle; goto epilogue.
9. `ioctlsocket(FIONBIO=0x8004667E, nonBlocking)`.
10. If TCP **and** `address[1] != 0`: `listen(sock, 5)` (log on fail; does **not** invalidate).
11. **Record journal** (`DAT_00d179e4 == 1` && `DAT_00d179e0`): write handle via `BitStream_writeBits(0x20)`.
12. Return `this`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00785510_TNL_Socket_Constructor.md` |
| Raw | `docs/reconstruction/raw/aa_00785510_FUN_00785510.md` (legacy id) + rename target |
| Annotated | `docs/reconstruction/raw/aa_00785510_FUN_00785510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00785510.cpp` / `Named_Socket_Socket.cpp` |

**Live tools (OWN VA only):**

- `decompile_function` @ `0x00785510` — full body matches raw plate `TNL_Socket_Constructor`.
- `read_memory` body entry / FIONBIO immediate / epilogue `ret 0x18`.
- `read_memory` transport name table @ `0x00a9b180` → `"IPX\0TCP\0UDP\0Socket::Socket"`.
- `get_xrefs_to` — **2** code callers: `FUN_0042c010` @ `0x0042c070`, `FUN_0042d440` @ `0x0042d4ae`.
- `get_function_by_address` — body `00785510`–`00785c0d`.
- **Not performed:** Launcher; runtime golden; bit-exact image diff; callee duals (`FUN_00784490` / `007843e0` / `00784560` / `00783ee0` / log helpers) — out of OWN VA.

---

## 3. Calling convention (OWN body sealed)

| Slot | Role | Evidence |
|---|---|---|
| **arg0** stack | `Socket *this` | Entry `mov ebp,[esp+…]`; epilogue `mov eax,ebp` |
| **arg1** stack | `Address *` / transport+bind info (`ushort *`) | `mov esi,[esp+…]`; `*esi` = type; `esi[1]` listen gate |
| **arg2** stack | `U32 sendBufferSize` | `setsockopt SO_SNDBUF` `&param_3` |
| **arg3** stack | `U32 recvBufferSize` | `setsockopt SO_RCVBUF` `&param_4` |
| **arg4** stack | `U32 allowBroadcast` (byte-used) | `setsockopt SO_BROADCAST`; skipped when type==1 |
| **arg5** stack | `byte nonBlocking` | `ioctlsocket FIONBIO` |
| **Return** | `this` in **EAX** | `mov eax,ebp` |
| **ABI** | **stdcall**, **6×4 = 24** bytes | Trailer `c2 18 00` @ end of body |

Entry (sealed):

```
83 ec 28          sub  esp, 0x28
53                push ebx
55                push ebp
8b 6c 24 34       mov  ebp, [esp+0x34]   ; this
...
56                push esi
8b 74 24 3c       mov  esi, [esp+0x3c]   ; Address*
89 5d 08          mov  [ebp+8], ebx      ; this+8 = 0
89 5d 0c          mov  [ebp+0xc], ebx    ; this+0xc = 0
```

Epilogue (sealed @ `0x00785c05`…):

```
5e                pop  esi
8b c5             mov  eax, ebp
5d                pop  ebp
5b                pop  ebx
83 c4 28          add  esp, 0x28
c2 18 00          ret  0x18
```

---

## 4. Object layout (this)

| Offset | Field | Evidence |
|---:|---|---|
| `+0x00` | `SOCKET handle` | `*this = socket(...)` / `0xffffffff` fail |
| `+0x04` | `U32 transportType` | `this[1] = (uint)*address` |
| `+0x08` | TCP aux A (or 0) | zeroed; filled only type==1 via `FUN_00783ee0` |
| `+0x0c` | TCP aux B (or 0) | same |

Size used by ctor body: **≥ 0x10** bytes. Full class size residual (embedded in NetInterface at `+0x1a` dwords in caller — out of OWN).

---

## 5. Winsock / transport constants (sealed)

| Constant | Value | Use |
|---|---:|---|
| `AF_INET` | `2` | UDP + TCP `socket` |
| `AF_IPX` | `6` | IPX `socket` |
| `SOCK_STREAM` | `1` | TCP |
| `SOCK_DGRAM` | `2` | UDP + IPX |
| `NSPROTO_IPX` | `1000` | IPX protocol |
| `SOL_SOCKET` | `0xFFFF` | all `setsockopt` level |
| `SO_SNDBUF` | `0x1001` | send buffer (`param_3`) |
| `SO_RCVBUF` | `0x1002` | recv buffer (`param_4`) |
| `SO_BROADCAST` | `0x20` | broadcast enable (`param_5`) |
| `FIONBIO` | `0x8004667E` | nonblock ioctl — body `push 0x8004667e` (`68 7e 66 04 80`) |
| `INVALID_SOCKET` | `0xFFFFFFFF` | fail / pre-create |
| TCP `listen` backlog | `5` | TCP + `address[1] != 0` |

Transport name strings (`read_memory` @ `0x00a9b180`):

| VA | String | Type enum |
|---:|---|---:|
| `0x00a9b180` | `IPX` | 2 |
| `0x00a9b184` | `TCP` | 1 |
| `0x00a9b188` | `UDP` | 0 |

Journal plate string: `"Socket::Socket"` (record + playback stamp blocks).

---

## 6. Callers (xref sealed; bodies not owned)

| Caller VA | Site | Notable args |
|---|---|---|
| `FUN_0042c010` @ `0x0042c070` | NetInterface-style embed `this+0x1a` | `(addr, 0x8000, 0x8000, 1, 1)` |
| `FUN_0042d440` @ `0x0042d4ae` | heap Socket | `(addr, 1000000, 1000000, 1, 1)` |

Both pass **broadcast=1**, **nonBlocking=1**. Buffer sizes differ (32 KiB vs 1_000_000).

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name `TNL_Socket_Constructor` / plate `Socket::Socket` | **High** | Ghidra symbol + journal strings |
| Body span + stdcall `ret 0x18` | **High** | `read_memory` epilogue |
| Transport 0/1/2 = UDP/TCP/IPX | **High** | socket() triples + string table |
| SO_RCVBUF=`param_4`, SO_SNDBUF=`param_3` | **High** | decompile order + option constants |
| Broadcast skipped for TCP | **High** | `if (this[1] != 1)` before SO_BROADCAST |
| FIONBIO immediate `0x8004667E` | **High** | body bytes |
| TCP listen when `address[1] != 0`, backlog 5 | **High CF** | live decompile; **+2 field English** Probable (port/listen) |
| `param_2` full TNL `Address` layout | **Probable** | type@0 sealed; bind via `FUN_00784490` residual |
| Journal mode globals `DAT_00d179e4` 1=record / 2=playback | **High CF** | branch shapes; product names residual |
| Send-buffer success log prints `param_4` not `param_3` | **High** | decompile log line uses wrong arg (retail log quirk) |
| Clean ≡ raw CF | **High** | scaffold rewrite |
| AutoCore `TNLSocket` parity | **Low / gap** | C# is UDP-only `UdpClient` wrapper — not this full ctor |
| Bit-for-bit / runtime / diff | **Open** | deferred |

---

## 8. Control-flow checklist

| Stage | Match |
|---|---|
| Zero TCP aux `+8/+0xc` | **Yes** |
| Playback early path (`mode==2`) | **Yes** |
| `*this = INVALID`; type store | **Yes** |
| UDP/TCP/IPX socket branches | **Yes** |
| Invalid transport log | **Yes** |
| Fail if handle still INVALID → epilogue | **Yes** |
| bind → RCVBUF → SNDBUF chain with error close | **Yes** |
| Broadcast only non-TCP | **Yes** |
| FIONBIO always on success path | **Yes** |
| TCP listen optional; fail does not close | **Yes** |
| Record path writes handle | **Yes** |
| Return this | **Yes** |

---

## 9. Gaps

1. Full TNL `Address` layout beyond `ushort type` + `ushort [1]` listen gate (callee `FUN_00784490` / `FUN_007843e0`).
2. Identity of TCP aux ctor `FUN_00783ee0` (0x18-byte objects at `+8/+0xc`).
3. Journal subsystem globals product names (`DAT_00d179e4` / `DAT_00d179e0` / BitStream session).
4. `FUN_00784560` pre-create (WSAStartup vs Address init).
5. AutoCore port: `lib/TNL.NET/.../TNLSocket.cs` does not mirror multi-transport ctor / buffer / broadcast options.
6. Runtime + image bit-diff not run.

**Verdict:** **accept-with-gaps** — OWN body transport/bind/option/journal CF sealed; Address field English + TCP aux + AutoCore port depth remain open.
