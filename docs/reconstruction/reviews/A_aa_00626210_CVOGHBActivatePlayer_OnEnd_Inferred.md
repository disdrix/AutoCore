# Review A (reconstruction fidelity): `aa_00626210` CVOGHBActivatePlayer_OnEnd_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626210` |
| **VA** | `0x00626210`–`0x0062623a` (43 B / `0x2B`; pad `CC` after) |
| **Canonical name** | `CVOGHBActivatePlayer_OnEnd_Inferred` (Ghidra `FUN_00626210`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W29-P) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` |
| **System** | heartbeat / timed-actions / player activate |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` / `get_function_by_address` / xrefs. **No** `disassemble_bytes`. Sibling: W28-G ctor, W27-F activate parent, base Stop/EndOrDestroy duals.

---

## 1. Purpose

**Activate-player HB OnEnd** virtual installed at `vtbl 0x009e3168 + 0x14`:

1. Gate: `host = *(this+0x24) != 0` **and** `*(this+0x28) == 0`
2. `*(uint8_t*)(host+0x6c8) = 1`
3. `host->vtbl[+0x18](1, 1)` (thiscall host)
4. **Tail-jmp** empty `FUN_005081f0` (`C3`)

Does **not** free, dequeue, set dormant, or write `this+0x28`.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00626210_FUN_00626210.md` | Append re-verify |
| Annotated | `docs/reconstruction/raw/aa_00626210_FUN_00626210.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_OnEnd_Inferred.cpp` | New |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00626210.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_00626210_FUN_00626210.md` | Updated |
| Live decompile | Ghidra @ `0x00626210` | ≡ raw CF |
| Live bytes | `read_memory` 64 B | body + pad + tail target |
| Vtbl | `read_memory` @ `0x009e3168` | slot `+0x14` = this VA |
| Empty tail | `read_memory` @ `0x005081f0` | `C3` |
| Ctor dual | W28-G `CVOGHBActivatePlayer_ctor_Inferred` | `+0x24`/`+0x28` fields |

**Not performed:** Launcher, runtime golden, host `vtbl+0x18` body dual, RTTI name recovery.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this (activate-player HB)
// no stack args; void (tail-jmp empty RET)
void CVOGHBActivatePlayer_OnEnd_Inferred(void *this);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | `56 8B F1` | **High** |
| No stack args / plain exit | no `C2`; jmp to `C3` | **High** |
| Body 43 B | `get_function_by_address` end `0062623a` | **High** |
| Gate host + `+0x28` | `test eax` / `cmp [esi+0x28],0` | **High** |
| `host+0x6c8 = 1` | `C6 80 C8 06 00 00 01` | **High** |
| Host vcall `+0x18` with `(1,1)` | `6A 01 6A 01 FF 50 18` | **High** |
| DATA only xref | `0x009e317c` | **High** |
| OnEnd slot role | base Stop/EndOrDestroy dispatch `+0x14` | **High** |
| Product method name | structural from class + slot | **Inferred** |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Host null / flag skip | **Yes** |
| Host `+0x6c8` store then vcall | **Yes** |
| Always empty tail | **Yes** (bytes: tail-jmp; decomp call ≡) |
| No free / list / period ops | **Yes** |

---

## 5. Gaps / open

1. Product/PDB OnEnd spelling for class of vtbl `0x009e3168`.
2. Host `vtbl+0x18` English (args sealed; body not OWN).
3. Exhaustive semantic catalog of `host+0x6c8` readers (sibling gates known).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — CF/ABI/vtbl slot/host side effects sealed; product + host-vfunc English open.
