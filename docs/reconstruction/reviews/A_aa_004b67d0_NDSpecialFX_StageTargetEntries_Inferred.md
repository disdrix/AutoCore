# Review A (reconstruction fidelity): `aa_004b67d0` NDSpecialFX_StageTargetEntries_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b67d0` |
| **VA** | `0x004b67d0` |
| **Canonical name (Ghidra)** | `FUN_004b67d0` |
| **Proposed name** | `NDSpecialFX_StageTargetEntries_Inferred` (**High** role; product symbol absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004b67d0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004b67d0_NDSpecialFX_StageTargetEntries_Inferred.md` |
| **System** | `client-fx` / combat hit staging on NDSpecialFX host |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**One-shot stage of target identity + fixed-size entry blob** onto an NDSpecialFX-sized host that owns:

| Offset | Field |
|---|---|
| `+0x3C` | pointer to `count × 0x20` heap entries (null when empty) |
| `+0x40` | entry count |
| `+0x48`–`+0x57` | 16-byte identity block (TFID / COID pair region — consumed as `TFID_16*` by sibling `FUN_004b6980`) |

Control flow:

1. Copy **4 dwords** from `param_4` → `this+0x48..+0x54`.
2. If `this+0x3C == null`:
   - Zero `+0x3C` (already null).
   - If `param_3 != 0`: store count at `+0x40`, `operator_new__(param_3 << 5)` → `+0x3C`, dword-copy `param_3*0x20` bytes from `param_2`.
   - Return.
3. If `this+0x3C != null`: `operator_delete(+0x3C)` only (no re-stage). Decompiler marks delete **noreturn** — known false (control would fall off; callers treat as replace-once / assert path).

**Not** multi-hit apply (`004da2e0`), not list teardown (`004b85d0`), not map erase (`004bacf0`).

Sole live caller: weapon/FX path `FUN_0056bab0` stages a single target (`count=1`, identity at `obj+0x160`) when the FX session flag at `fx+0xc` is set; otherwise `0056bab0` calls `004da2e0` directly.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004b67d0` |
| Callers | `get_function_callers` / xrefs → `FUN_0056bab0` only |
| Consumer sibling | live `FUN_004b6980` (reads `+0x3C`/`+0x40`/`+0x48`, calls `004da2e0`, frees `+0x3C`) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004b67d0` |
| Function record | `docs/reconstruction/functions/aa_004b67d0_FUN_004b67d0.md` |
| Teardown peer | `A_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred.md` (frees `+0x3C`) |

**This pass:** live decompile; callers; sibling consumer. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = host with +0x3C/+0x40/+0x48 layout
void __thiscall NDSpecialFX_StageTargetEntries_Inferred(
    void *host,          // this
    const void *entries, // param_2 — source of count×0x20 bytes
    int count,           // param_3
    const void *id16);   // param_4 — 16-byte identity → host+0x48
```

---

## 4. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0056bab0` @ `0x0056bab0` | Weapon FX hit path; stages when session `+0xc` non-zero |
| Callee | `operator_new__` | `count << 5` bytes |
| Callee | `operator_delete` | only when `+0x3C` already non-null |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Copy 16B id → `+0x48` | Yes |
| Gate `+0x3C == 0` then optional alloc/copy | Yes |
| Empty count (`param_3==0`) returns without alloc | Yes |
| Non-null `+0x3C` → delete only | Yes |
| Byte residual loop `iVar3=0` dead | Yes (artifact; size always dword-aligned) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stages id@`+0x48` + optional `count×0x20` @`+0x3C` | **High** | Body |
| Element stride `0x20` | **High** | `param_3 << 5` |
| One-shot when `+0x3C` empty; delete-only if set | **High** | CF |
| Consumed later by `004b6980` → `004da2e0` | **High** | sibling decompile |
| Host is NDSpecialFX / shared FX staging layout | **Probable** | teardown frees `+0x3C`; layout peers |
| Product symbol | **Tentative** | `_Inferred` |
| Exact 16B identity type (TFID vs COID pair) | **Probable** | `004b6980` passes `+0x48` to `Object_ResolveFromTFID` |

---

## 7. Gaps / open

1. Full product type of host (NDSpecialFX vs dedicated hit-stage subobject).
2. Layout of each `0x20` entry (paired TFID stride matches multi-hit walk in `004da2e0`).
3. Whether non-null `+0x3C` path is intentional single-use assert vs incomplete replace.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — staging CF High; product naming + entry schema open.
