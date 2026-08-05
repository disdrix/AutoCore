# Review A (reconstruction fidelity): `aa_0067ba30` netSocket_GetPeerAddress

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067ba30` |
| **VA** | `0x0067ba30` |
| **Body span** | `0067ba30` – `0067bab8` |
| **Canonical name** | `FUN_0067ba30` |
| **Proposed name** | `netSocket_GetPeerAddress` / `NetSocket_GetPeerName` |
| **System** | network-nazgul-netSocket |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_0067ba30_netSocket_GetPeerAddress.md` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Nazgul **`netSocket` peer-address query**: given a socket object in **ECX** with OS `SOCKET` at `+0`, call Winsock **`getpeername`**, write the 16-byte result into an out **Address**, return the out pointer.

Stages (live decompile ≡ raw CF):

1. Install SEH (`LAB_009a962c`), state = −1.
2. Default-construct stack Address temp via `FUN_0067b070` (zeros + `htons(0)` port).
3. SEH state = 1; set `namelen = 0x10`.
4. `getpeername(*this, &temp, &namelen)`.
5. `FUN_0067b0e0(out, &temp)` — 4× dword copy into out Address.
6. Clear SEH state low byte; `FUN_0067b110()` trivial dtor of temp.
7. Unlink SEH; **return out** in EAX.

**Twin:** `FUN_0067b9a0` @ `0x0067b9a0` — identical shape with **`getsockname`** (local name).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0067ba30_FUN_0067ba30.md` |
| Raw | `docs/reconstruction/raw/aa_0067ba30_FUN_0067ba30.md` (+ v2026-07-29 section) |
| Annotated | `docs/reconstruction/raw/aa_0067ba30_FUN_0067ba30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0067ba30.cpp` |
| Named twin | `…/Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0067ba30.cpp` |

**Live tools (OWN VA only):**

- `decompile_function` @ `0x0067ba30` — identity with prior raw scaffold.
- `read_memory` entry (SEH + `mov esi,ecx` + call `FUN_0067b070`) and full body through `ret 4`.
- `read_memory` / decompile of **callees for context only** (`0067b070`, `0067b0e0`, `0067b110`) — not dual-owned here.
- Twin decompile `FUN_0067b9a0` for peer-vs-local seal.
- Sibling string path via `FUN_0067b680` / `FUN_0067baf0`: `…\nazgul\net\netSocket.cpp`.
- **Not performed:** Launcher; runtime golden; bit-exact image diff; parent ledger edits; callee dual seals.

---

## 3. Calling convention (OWN body sealed)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | `SOCKET*` / `netSocket* this` | Entry `8b f1` (`mov esi, ecx`); `getpeername(*esi, …)` via `8b 16` |
| **stack arg0** | `Address* out` | After getpeername: `8b 74 24 2c` reloads ESI from stack; dest of copy; returned |
| **Return** | `out` in **EAX** | `8b c6` (`mov eax, esi`) |
| **ABI** | `__thiscall` + 1 stack arg | Trailer `c2 04 00` (`ret 4`) |

Epilogue seal (`read_memory`):

```
e8 6b f6 ff ff       call FUN_0067b110
8b 4c 24 1c          mov  ecx, [esp+0x1c]
8b c6                mov  eax, esi
5e                   pop  esi
64 89 0d 00 00 00 00 mov  fs:[0], ecx
83 c4 24             add  esp, 0x24
c2 04 00             ret  4
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = peer address via `getpeername` | **Confirmed** | decompiler import + twin getsockname |
| `this` in ECX; `*this` is OS SOCKET | **Confirmed** | entry + `getpeername` first arg |
| Out Address 16 bytes (`namelen=0x10`) | **Confirmed** | `c7 … 10 00 00 00` |
| Copy via `FUN_0067b0e0` (4 dwords) | **Confirmed** | call after getpeername |
| Trivial temp dtor `FUN_0067b110` | **Confirmed** | empty body sealed under OWN sibling VA |
| Return = out pointer | **Confirmed** | `mov eax,esi` after ESI=out |
| `ret 4` / stdcall stack portion | **Confirmed** | trailer bytes |
| Family = nazgul `netSocket` | **High** | sibling `.cpp` string; SOCKET-at-+0 layout matches `Named_netSocket_*` |
| Product/PDB method spelling | **Open** | inferred `GetPeerAddress` / `GetPeerName` |
| Full Address field layout beyond 16B overlay | **Probable** | copy is opaque 16B; field English residual |
| Auth `+0x30`/`+0x34` which slot is `this` | **Open** | caller duals |
| Clean ≡ raw ≡ live CF | **Confirmed** | scaffold rewrite |
| Bit-for-bit / runtime / diff | **Open** | deferred |

---

## 5. Control-flow checklist

| Stage | Match |
|---|---|
| SEH install state −1, handler `LAB_009a962c` | **Yes** |
| Default-construct temp (`FUN_0067b070`) | **Yes** |
| SEH state = 1; namelen = 0x10 | **Yes** |
| `getpeername(*this, &temp, &namelen)` | **Yes** |
| Copy temp → out (`FUN_0067b0e0`) | **Yes** |
| Clear SEH; `FUN_0067b110` temp dtor | **Yes** |
| Restore ExceptionList; return out | **Yes** |
| No closesocket / no error branch in OWN body | **Yes** (unchecked getpeername result) |

### Recovered CF (faithful)

```c
// __thiscall: ECX = netSocket*, stack = Address* out, returns out
Address* __thiscall FUN_0067ba30(SOCKET *self, Address *out)
{
    // SEH …
    Address temp;                 // FUN_0067b070
    int namelen = 0x10;
    getpeername(*self, (sockaddr*)&temp, &namelen);
    *out = temp;                  // FUN_0067b0e0
    // FUN_0067b110(); temp dtor
    return out;
}
```

---

## 6. Gaps

1. Product/PDB name not recovered from strings on this VA.
2. `getpeername` failure ignored — no error return path in body (callers may not check).
3. Auth object slots binding ECX (`+0x30` vs `+0x34`) need caller duals.
4. Address field English (family/port/ip layout) residual to Address duals.
5. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — ABI, CF, peer-vs-local twin, and 16B out contract sealed for AutoCore network/auth ports.
