# Review A (reconstruction fidelity): `aa_0092af80` TargetFilter_DispatchMatchArms_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092af80` |
| **VA** | `0x0092af80`–`0x0092b011` (146 B); pad `CC` @ `0x0092b012+` |
| **Canonical name** | `TargetFilter_DispatchMatchArms_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Path A — reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0092af80_TargetFilter_DispatchMatchArms_Inferred.md` |
| **System** | inventory-transfer (R11 partition) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` body `0x0092af80` (256 B) + caller site `0x0092bfb0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Multi-arm **target-filter dispatcher**: given a filter context, optionally resolve a direct COID, then run zero-or-more nearest/scan arms that update `*bestOut` / `*bestDistSq`. Returns whether **any arm was eligible**, not whether a non-null hit exists.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw (+ R11 append) | `docs/reconstruction/raw/aa_0092af80_FUN_0092af80.md` |
| Annotated | `docs/reconstruction/raw/aa_0092af80_FUN_0092af80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/TargetFilter_DispatchMatchArms_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092af80.cpp` |
| Function records | `functions/aa_0092af80_*.md` |
| Dualed child arm | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` `0x0092adf0` |
| Dualed resolve | `CVOGReaction_ResolveObjectTarget` `0x004bae70` |
| Counterpart B | `reviews/B_aa_0092af80_TargetFilter_DispatchMatchArms_Inferred.md` |

---

## 3. Signature (sealed)

```c
// EAX = TargetFilterCtx* (*ctx = Client*)
// ESI = Object **bestOut
// stack cleaned by ret 8
bool TargetFilter_DispatchMatchArms_Inferred(float *origin, float *bestDistSq);
```

Bytes: prologue `PUSH EBX; PUSH EBP; MOV EBP,[ESP+10]; PUSH EDI; MOV EDI,EAX`; epilogue `POP EDI; POP EBP; POP EBX; ret 8`.

---

## 4. Sealed facts

1. **Body size** 146 B; `ret 8` sealed.
2. **Direct COID gate:** `(ctx+0x20 & ctx+0x24) != -1` then Resolve with `bGlobal=0`, write `*ESI`.
3. **Resolve thiscall:** `ECX = *(*(ctx)+0xD34)`; relative E8 lands on dualed `0x004bae70`.
4. **Count gates** signed `> 0` at `+0x28`, `+0x80`, `+0x54`, `+0xAC` — order matches decompile.
5. **Child arm `+0x28`:** dualed CBID nearest + locker absence (`0x0092adf0`); stack `(origin, bestOut, bestDistSq)`, EDI=ctx.
6. **Arm `+0x54`:** `MOV EBX,EDI` before `0092a980` (callee ctx in EBX).
7. **Arm `+0xAC`:** `0092a760`; on `TEST AL,AL` zero → `00929cd0` with extra `PUSH EDI` (ctx first).
8. **Return:** sticky `MOV AL,1` per fired arm; initial `XOR AL,AL`.
9. **Sole caller:** `FUN_0092bf60` @ `0x0092bff5` — pos via vtbl `+0x1A0`, max dist `DAT_00aaaaf8` (`0x4E6E6B28`), `LEA ESI` bestOut slot.
10. **Decompile ≡ CF**; ABI register formals corrected via bytes (no `disassemble_bytes`).

---

## 5. Gaps

- Product/PDB method + filter-ctx class English.
- Residual arms `0092abc0` / `0092a980` / `0092a760` / `00929cd0` not dual-owned here.
- Runtime / bit-exact / differential.
- Grandcaller `0092bf60` residual (R11-040 partition neighbor — not edited).

---

## 6. Verdict rationale

CF, ABI, arm order, dualed callees, sole call site, and return semantics are image-sealed. Naming is role-accurate `_Inferred`. Residual arm interiors and product English keep the unit out of full accept.

**Path A: accept-with-gaps.**
