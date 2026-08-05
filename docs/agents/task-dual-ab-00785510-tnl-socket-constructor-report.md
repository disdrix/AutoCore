# Dual A/B report — `aa_00785510` TNL_Socket_Constructor

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00785510`. Dual A/B + three-rep strengthen.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `get_xrefs_to` + `get_function_by_address` (no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00785510` TNL_Socket_Constructor | **accept-with-gaps** — ABI/transport/options/journal CF sealed; Address English + TCP aux + AutoCore port open |

---

## Sealed facts

1. **Role:** TNL **`Socket::Socket` constructor** (plate string `"Socket::Socket"`). Not a free-standing Winsock wrapper name — first arg is **Socket object**, OS handle at `+0`.

2. **Body span:** `0x00785510` – `0x00785c0d`.

3. **ABI:** **stdcall**, **6** stack arguments, **`ret 0x18`**, returns **this** in EAX (`mov eax, ebp` epilogue). **Not** ECX-thiscall.

4. **Signature map:**

   | Arg | Role |
   |----:|------|
   | 0 | `Socket *self` |
   | 1 | `Address *` (`ushort type` @0; `[1]` TCP listen gate) |
   | 2 | send buffer → **SO_SNDBUF** `0x1001` |
   | 3 | recv buffer → **SO_RCVBUF** `0x1002` |
   | 4 | allow broadcast → **SO_BROADCAST** `0x20` (non-TCP only) |
   | 5 | nonBlocking → **FIONBIO** `0x8004667E` |

5. **Transport create:**

   | type | socket() | name @ |
   |-----:|----------|--------|
   | 0 UDP | `(AF_INET=2, SOCK_DGRAM=2, 0)` | `0x00a9b188` |
   | 1 TCP | `(2, SOCK_STREAM=1, 0)` + two `new(0x18)`/`FUN_00783ee0` @ `+8/+0xc` | `0x00a9b184` |
   | 2 IPX | `(AF_IPX=6, SOCK_DGRAM=2, 1000)` | `0x00a9b180` |

6. **Init chain:** setup → create → bind (Address helper) → RCVBUF → SNDBUF → [broadcast if !TCP] → FIONBIO → [listen(5) if TCP && address[1]!=0]. Bind/buf/broadcast fail → `closesocket` + `INVALID_SOCKET`. Listen fail → log only.

7. **Journal:** `DAT_00d179e4==2` playback `BitStream_readBits(32)` handle; `==1` record `BitStream_writeBits(32)`.

8. **Xrefs (2):** `FUN_0042c010` @ `0x0042c070` (`0x8000/0x8000/1/1`); `FUN_0042d440` @ `0x0042d4ae` (`1000000/1000000/1/1`).

9. **FIONBIO** sealed in body bytes: `68 7e 66 04 80` = `push 0x8004667e`.

10. **AutoCore gap:** `lib/TNL.NET/TNL.NET/Network/TNLSocket.cs` is UDP-only `UdpClient` — does not port multi-transport ctor, SO_* buffers, broadcast, or journal.

---

## Gaps

1. Full TNL `Address` layout / `address[1]` English (port vs listen flag) — needs `FUN_00784490` dual.  
2. TCP aux `FUN_00783ee0` product type.  
3. Journal global product names.  
4. `FUN_00784560` pre-create identity.  
5. Runtime / image bit-diff.  
6. AutoCore incomplete port (document only; no code change this task).

---

## Dual A/B

| Review | Path | Verdict |
|--------|------|---------|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00785510_TNL_Socket_Constructor.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00785510_TNL_Socket_Constructor.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00785510_TNL_Socket_Constructor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00785510_TNL_Socket_Constructor.md` |
| Function record | `docs/reconstruction/functions/aa_00785510_TNL_Socket_Constructor.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/TNL_Socket_Constructor.cpp` |
| Raw (pre-existing) | `docs/reconstruction/raw/aa_00785510_FUN_00785510.md` |
| Annotated (pre-existing) | `docs/reconstruction/raw/aa_00785510_FUN_00785510.annotated.md` |
| Legacy clean scaffolds | `docs/reconstruction/reconstructed-exact/FUN_00785510.cpp`, `Named_Socket_Socket.cpp` |
| This report | `docs/agents/task-dual-ab-00785510-tnl-socket-constructor-report.md` |

---

## AutoCore impact

- **No mandatory port change** for current UDP `UdpClient` path if product never needs TCP/IPX/journal.  
- If fuller TNL Socket parity is required: map ctor args as above; keep RCV=`recv`, SND=`send`; skip broadcast on TCP; always set nonblocking for game sockets (both native callers use `1`).  
- Do not invert buffer parameters; do not treat listen failure as fatal close.
