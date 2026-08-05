# Review A (reconstruction fidelity): `aa_007b75b0` AssManager_InitPrecompileAndResolvers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b75b0` |
| **VA** | `0x007b75b0`–`0x007b7b6d` (**~1469 B**) |
| **Canonical name** | `AssManager_InitPrecompileAndResolvers_Inferred` |
| **Ghidra name** | `FUN_007b75b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-D) |
| **Counterpart** | `reviews/B_aa_007b75b0_AssManager_InitPrecompileAndResolvers_Inferred.md` |
| **System** | `assets` / `assManager` / `NDAssetManager` |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (entry/epilogue/call-site/strings) + `analyze_function_complete`; 2 callers |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Client bootstrap worker:

1. Ensure `"../effects"` then `"../effects/precompile"` exist (mkdir / helpers); on failure log NDAssetManager.cpp:0x282 and use `"."`.
2. Publish path to assManager host (`DAT_00d1f058+0xb4`), set `+0xd0=1`, run side inits.
3. If `self+0x04` bit0: construct 0x4c resolver → `self+0x08`; find/push on `host+0x58` via `GuardedVector_PushBackLocked`; walk string bag.
4. If bit1: construct 0x5c resolver → `self+0x0c`; find/push under **host** CS + raw PushBack; batch `FUN_00984ee0(1)` (mode-gated extra count).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b75b0_FUN_007b75b0.md` (+ W30-D live seal) |
| Annotated | `docs/reconstruction/raw/aa_007b75b0_FUN_007b75b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_InitPrecompileAndResolvers_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007b75b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b75b0_FUN_007b75b0.md` |
| Named record | `docs/reconstruction/functions/aa_007b75b0_AssManager_InitPrecompileAndResolvers_Inferred.md` |
| Live | decompile ≡ raw CF; body range; RET 8; 2 xrefs |
| Strings | `read_memory` @ `0x00a95ebc`, `0x00a95e10`, `0x00a95e58`, `0x00a9e8a4` |
| Call site A insert | `EDI=*DAT_00d1f058+0x58` then `CALL 0043c4f0` @ `0x007b77ba` |

---

## 3. Signature (sealed)

```c
// stdcall 2 formals; RET 0x8
void AssManager_InitPrecompileAndResolvers_Inferred(
    AssManagerClientState* self /*stack*/,
    char mode /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack[0] | **High** |
| mode | Stack[1] char | **High** |
| cleanup | **`RET 0x8`** (`C2 08 00`) | **High** |
| flags | `self+0x04` | **High** |
| resolvers | `self+0x08` / `+0x0c` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Path loop + `/precompile` | **Yes** | **High** |
| Mkdir fail → log + `"."` | **Yes** | **High** |
| host+0xb4 / +0xd0 side init | **Yes** | **High** |
| Bit0 → A construct + PushBackLocked | **Yes** | **High** |
| Bit1 → B construct + host CS + PushBack | **Yes** | **High** |
| Duplicate A soft / B hard | **Yes** | **High** |
| `FUN_00984ee0` batch + mode gate | **Yes** (count from decompile) | **High** |
| Nested helper free semantics | shape only | **Open** |
| Product method English | inferred | **Inferred** |

---

## 5. Gaps

1. Product/PDB method name (plates show files, not method).
2. Resolver class types (`00423be0` 0x4c; 0x5c + `PTR_FUN_00aa1f1c`).
3. Exact contracts of `FUN_00984ee0`, `FUN_00754280`, `FUN_00989ef0`, path helpers (not OWN).
4. Runtime / bit-exact / live filesystem.

---

## 6. Verdict

ABI, path/precompile CF, flag-driven dual resolver registration, host+0x58 list, and string evidence sealed → residual nested free + product English → **accept-with-gaps**.
