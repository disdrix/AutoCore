# OWN-ONLY dual agent report — W25-P

| Field | Value |
|---|---|
| Agent | W25-P |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0067b0e0`, `0x00718250` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0067b0e0` `netAddress_CopyAssign` | **accept-with-gaps** — 34 B thiscall ret 4; 4× dword Address POD copy sealed; product English open |
| `aa_00718250` `_com_error_ScalarDeletingDtor` | **accept** — 43 B MSVC scalar deleting dtor; `~_com_error` + flags&1 `operator_delete`; vftable slot0 sealed; CRT not game |

---

## VA `0x0067b0e0` — netAddress_CopyAssign

| Field | Value |
|---|---|
| Ghidra | `FUN_0067b0e0` |
| Canonical | `netAddress_CopyAssign` (**High** role; product open) |
| Body | `0x0067b0e0`–`0x0067b102` exclusive (**34** / `0x22` B); last `ret 4` |
| Role | POD copy of 16-byte Address: `dest[0..3] = src[0..3]` |
| ABI | **thiscall** ECX=dest, stack src; **`ret 4`**; void |
| Callers | `FUN_0067ba30`, `FUN_0067b9a0`, `FUN_00671570`, `FUN_0067c060`, `FUN_0067c120` |
| Callees | none |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **Bytes:** full 34 B via `read_memory`; hex ends `…5ec20400`.
2. **ABI:** ECX dest saved to EAX/EDX; `[esp+4]` src; four dword stores; `ret 4`.
3. **Cluster:** Address POD with ctor `0067b070`, dtor `0067b110`, assign `0067b120` (siblings).
4. **Size:** 16 bytes (matches GetPeer/GetSock `namelen=0x10`).

### Gaps

1. Product English (`netAddress` vs `Address`).
2. Field-level sockaddr layout names.
3. Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0067b0e0_netAddress_CopyAssign.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0067b0e0_netAddress_CopyAssign.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0067b0e0_FUN_0067b0e0.md`
- `docs/reconstruction/raw/aa_0067b0e0_FUN_0067b0e0.annotated.md`
- `docs/reconstruction/reconstructed-exact/netAddress_CopyAssign.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0067b0e0.cpp`
- `docs/reconstruction/functions/aa_0067b0e0_netAddress_CopyAssign.md`
- `docs/reconstruction/functions/aa_0067b0e0_FUN_0067b0e0.md`
- `docs/reconstruction/reviews/A_aa_0067b0e0_netAddress_CopyAssign.md`
- `docs/reconstruction/reviews/B_aa_0067b0e0_netAddress_CopyAssign.md`

---

## VA `0x00718250` — _com_error_ScalarDeletingDtor

| Field | Value |
|---|---|
| Ghidra | `FUN_00718250` |
| Canonical | `_com_error_ScalarDeletingDtor` |
| Body | `0x00718250`–`0x0071827b` exclusive (**43** / `0x2B` B); last `ret 4` |
| Role | MSVC scalar deleting dtor for `_com_error` (vftable `0x00a14034` slot0) |
| ABI | **thiscall** ECX=this, stack flags; return this; **`ret 4`** |
| Callees | `~_com_error` @ `0x007182e0`; `operator_delete` |
| Xrefs | DATA from `0x00a14034` |
| Live ≡ raw | Yes (+ residual: decomp “does not return” on delete is false for CF) |
| **Verdict** | **accept** |

### Sealed facts

1. **Bytes:** full 43 B via `read_memory`; prologue frame; call `007182e0`; `flags & 1` gate; optional delete; return this.
2. **Vftable:** first dword at `0x00a14034` = `0x00718250`.
3. **Not game domain** — CRT COM; body resource policy lives in sibling `007182e0`.

### Gaps

1. Runtime / bit-exact.
2. Vector deleting path not on this VA (expected).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00718250__com_error_ScalarDeletingDtor.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00718250__com_error_ScalarDeletingDtor.md` | **accept** |

### Artifacts

- `docs/reconstruction/raw/aa_00718250_FUN_00718250.md`
- `docs/reconstruction/raw/aa_00718250_FUN_00718250.annotated.md`
- `docs/reconstruction/reconstructed-exact/_com_error_ScalarDeletingDtor.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00718250.cpp`
- `docs/reconstruction/functions/aa_00718250__com_error_ScalarDeletingDtor.md`
- `docs/reconstruction/functions/aa_00718250_FUN_00718250.md`
- `docs/reconstruction/reviews/A_aa_00718250__com_error_ScalarDeletingDtor.md`
- `docs/reconstruction/reviews/B_aa_00718250__com_error_ScalarDeletingDtor.md`

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### netAddress_CopyAssign (`0x0067b0e0`)

- Port as **16-byte POD assignment** / `memcpy(dest, src, 16)`.
- thiscall dest + stack src; no heap; no null check.
- Pair with sealed trivial dtor `0067b110` and peer/sock name helpers.

### `_com_error` scalar deleting dtor (`0x00718250`)

- **No server port** — client CRT COM only.
- Keep distinct from body dtor `007182e0` (delete gate lives only here).
