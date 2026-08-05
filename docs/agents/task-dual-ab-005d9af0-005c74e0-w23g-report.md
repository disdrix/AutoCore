# Dual A/B report — W23-G OWN `aa_005d9af0` + `aa_005c74e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-G  
**Scope:** VAs `0x005d9af0`, `0x005c74e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005d9af0` Drive_CollisionListener_PlayCollisionEffect | **accept-with-gaps** — string/ABI/CF sealed; float algebra + stack1/2 English residual |
| `aa_005c74e0` CLoadNode__initSpecialFX | **accept** — plate string + ABI + stage CF sealed |

---

## VA `0x005d9af0` — sealed facts

1. **Body:** `0x005d9af0`–`0x005d9e94` (932 B; `RET 0x14`).
2. **ABI:** **ECX**=CollisionListener* (FxMaster* @ `+4`); stack×5: float3*, a1, a2, gameObject*, allowCreate; void.
3. **String:** `"CollisionListener::PlayCollisionEffect"` @ `0x009db524`.
4. **Semantics:** Null-go reject → resolve clonebase FX (`go+0xA8`, gate `+0x88`) → optional lazy FxMaster → LoadEventVariant → vtbl+0x1C8 ×2 → SetParamFloat3 ×3 → play.
5. **Callers (2):** `Drive_CollisionListener_Contact` (flag=1), `FUN_005d9ea0` (flag=0).
6. **Constants:** 2.0f @ `a10e74`, 1.0f @ `a0f2a0`; `operator_new(8)`.
7. **Name:** `Drive_CollisionListener_PlayCollisionEffect` (Ghidra `FUN_005d9af0`).
8. **Decompile ≡ bytes** for CF; ABI formals filled from prologue/epilogue.

### Gaps

- stack1/stack2 product English.  
- Full float transform algebra bit-exact.  
- Nested callee depth (FxMaster / NDSpecialFX plates).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d9af0_Drive_CollisionListener_PlayCollisionEffect.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d9af0_Drive_CollisionListener_PlayCollisionEffect.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d9af0_FUN_005d9af0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d9af0_FUN_005d9af0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_PlayCollisionEffect.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d9af0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d9af0_FUN_005d9af0.md` |
| Function named | `docs/reconstruction/functions/aa_005d9af0_Drive_CollisionListener_PlayCollisionEffect.md` |
| Scratch | `docs/reconstruction/tmp/a_005d9af0.md` |

---

## VA `0x005c74e0` — sealed facts

1. **Body:** `0x005c74e0`–`0x005c76ed` (525 B; `RET 0x4`).
2. **ABI:** **ECX**=stage flags host* (clears `+0x62`); stack0=node*; **EAX** 1/0.
3. **String:** `"CLoadNode::_initSpecialFX"` @ `0x009da074`.
4. **Caller (1):** `FUN_005c7cd0` — gates `+0x62 && +0x51`; propagates if `eax!=1`.
5. **CF:** MI node → feature gate → hash lock walk → live `FUN_00542790` **or** offline map+`FUN_004a6390` return 0 → unlock → clear `+0x62` → return 1.
6. **Name:** `CLoadNode__initSpecialFX` (Ghidra `FUN_005c74e0`). Supersedes `Named_VOG_DEBUG_STOP_005c74e0`.
7. **Sibling stages:** `_initAnim`, `_initPhysics`, `_initFull`, …
8. **Decompile ≡ bytes** for CF; `local_410` residual = entry ECX.

### Gaps

- `DAT_00d1f050+0x6c` mode English.  
- Full hash iterator type.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005c74e0_CLoadNode__initSpecialFX.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005c74e0_CLoadNode__initSpecialFX.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005c74e0_FUN_005c74e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005c74e0_FUN_005c74e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initSpecialFX.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005c74e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005c74e0_FUN_005c74e0.md` |
| Function named | `docs/reconstruction/functions/aa_005c74e0_CLoadNode__initSpecialFX.md` |
| Scratch | `docs/reconstruction/tmp/a_005c74e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005d9af0` | Client collision VFX only — not server damage. Preserve allowCreate polarity (Contact=1, prep=0) and FxMaster cache at listener+4. |
| `005c74e0` | Client load stage — preserve return 1/0 and stage bit +0x62 clear; live path needs FxCache apply, offline may LoadMaster XML. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
