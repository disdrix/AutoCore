# Review B (skeptical / adversarial): `aa_00785510` TNL_Socket_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00785510` |
| **VA** | `0x00785510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00785510_TNL_Socket_Constructor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | This is a generic Winsock helper, not TNL Socket | **Falsified** — plate `"Socket::Socket"`, transport name table UDP/TCP/IPX, LogUDP channel, 2 NetInterface-family callers |
| 2 | Ghidra “SOCKET *” first arg means OS SOCKET value in/out | **Falsified** — first arg is **object pointer** (`this`); OS handle stored at `*this`; epilogue returns `this` |
| 3 | `__thiscall` (ECX = this) | **Falsified** — entry loads this from **stack**; trailer **`ret 0x18`** = stdcall 6 args; no ECX this |
| 4 | param_3/param_4 order is send then recv always in both setsockopt and logs | **Partially overstated** — **setsockopt** order is RCVBUF=`param_4` then SNDBUF=`param_3` (High); **success log for send** prints `param_4` (retail quirk / decompiler-visible bug) |
| 5 | Broadcast always applied | **Falsified** — skipped when `this+4 == 1` (TCP) |
| 6 | TCP listen failure invalidates the socket | **Falsified** — listen fail only logs; handle left open; no `closesocket` on that path |
| 7 | `ioctlsocket` arg `-0x7ffb9982` is mysterious | **Falsified as mystery** — equals **`FIONBIO` `0x8004667E`** (`push 0x8004667e` in body) |
| 8 | Type 2 is “raw” or “UNIX” | **Falsified** — `socket(6,2,1000)` + string `"IPX"` |
| 9 | Journal paths are dead / debug-only noise | **Overstated as dead** — full record/playback branches with BitStream 32-bit handle I/O; live only when mode globals set; **not** required for normal game path |
| 10 | AutoCore `TNLSocket` already ports this ctor | **Falsified** — C# uses `UdpClient` only; no TCP/IPX, no SO_* buffer pair, no broadcast setsockopt, no journal |
| 11 | Two callers pass identical buffer sizes so send/recv assignment is unobservable | **True for current call sites** (both args equal) — **does not** unseal SO_ assignment from body; body still binds RCV→param_4, SND→param_3 |
| 12 | `param_2[1]` is definitively “listen flag” not port | **Not sealed** — CF only tests `!= 0` before `listen`; could be port or dedicated flag — **Probable/open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = TNL Socket ctor | High | Mis-file under wrong system |
| stdcall 6-arg / return this | High | Wrong ABI in ports / hooks |
| Transport enum UDP/TCP/IPX | High | Wrong socket() family |
| SO_RCVBUF / SO_SNDBUF param map | High | Buffer sizing inverted in port |
| Broadcast non-TCP only | High | Enable broadcast on TCP (harmless fail) or skip UDP broadcast |
| FIONBIO nonblock | High | Blocking sockets → game loop stall |
| TCP aux pair @ +8/+0xc | High (alloc) / Medium (type) | Miss TCP-specific state |
| Address layout beyond type | Medium | Bind wrong host/port |
| Journal modes | High CF / Medium English | Break record/playback tools only |
| AutoCore parity | High that gap exists | Assume server UDP path matches retail options |

---

## 3. Surviving contract for AutoCore

```text
// Native VA 0x00785510 — TNL Socket::Socket (stdcall, 6 stack args, returns this)
//
// Socket* Socket_ctor(
//   Socket* self,
//   Address* bindAddress,   // ushort type @ +0; +2 gate for TCP listen
//   U32 sendBufferSize,     // SO_SNDBUF  (0x1001)
//   U32 recvBufferSize,     // SO_RCVBUF  (0x1002)
//   U32 allowBroadcast,     // SO_BROADCAST (0x20), non-TCP only
//   U8  nonBlocking);       // FIONBIO 0x8004667E
//
// self layout written here:
//   +0x00 SOCKET handle (or INVALID_SOCKET)
//   +0x04 U32 type (0=UDP, 1=TCP, 2=IPX)
//   +0x08 / +0x0c TCP-only 0x18-byte helpers (else 0)
//
// Create:
//   UDP: socket(AF_INET, SOCK_DGRAM, 0)
//   TCP: socket(AF_INET, SOCK_STREAM, 0) + two aux objects
//   IPX: socket(AF_IPX, SOCK_DGRAM, 1000)
// bind(Address→sockaddr via helper) → RCVBUF → SNDBUF → [broadcast if !TCP]
//   → FIONBIO → [listen(5) if TCP && address[1]!=0]
// Fail on bind/buf/broadcast: closesocket + INVALID; listen fail: log only
// Journal: mode2 playback reads handle; mode1 record writes handle (32 bits)
```

**Port rules (AutoCore):**

1. Primary game path is **UDP** + nonblocking + broadcast allowed (both native callers use `1,1` and UDP-class addresses).
2. Do **not** claim full parity while `TNLSocket` is UDP-only `UdpClient` without explicit SO_SNDBUF/RCVBUF / broadcast option surface.
3. Do **not** invert send/recv buffer parameters if a fuller port is added.
4. TCP/IPX/journal are **in-binary** but may remain unimplemented in server if product path never selects them — document as residual, do not invent.

**Do not confuse with:**

- Higher-level `NetInterface` / connection handshake (callers `FUN_0042c010` / `FUN_0042d440`).
- TNL BitStream packet protocol (only journal uses BitStream here for the **OS handle**).
- AutoCore `TNLConnection` RPC gates (different VAs).

---

## 4. Decompiler alias hazards (attack surface)

| Hazard | Mitigation |
|---|---|
| `param_1` reused as log format name pointer (`UDP`/`TCP`/`IPX` string) after real `this` copied to `pSVar3` | Treat log `%s` arg as transport name, not Socket* |
| `param_5` reused as nonblock ioctl arg and journal handle temp | Stage-local lifetimes; not one semantic |
| `SOCKET` typedef on object pointer | Object is struct; first field is OS SOCKET |
| Send log prints `param_4` | Log string is not authoritative for which buffer was set |

---

## 5. Open questions

1. Exact product spelling of `address+2` (port vs listen bool) — needs Address dual / `FUN_00784490`.
2. What `FUN_00783ee0` constructs (TCP notify/queue objects?).
3. Whether server AutoCore must ever open TCP/IPX (likely no for sector UDP).
4. Whether buffer sizes `0x8000` vs `1000000` at the two call sites matter for loss under load (runtime).

**Verdict:** **accept-with-gaps** — adversarial pass does **not** overturn transport/option/ABI seal; gaps are Address English, TCP aux product type, journal global names, and AutoCore incomplete port. Safe static map for OWN VA.
