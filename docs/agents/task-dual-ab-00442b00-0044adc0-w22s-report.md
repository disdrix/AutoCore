# Dual A/B report — W22-S OWN `aa_00442b00` + `aa_0044adc0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W22-S  
**Scope:** VAs `0x00442b00`, `0x0044adc0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00442b00` SkillSet_UninitializedCopy_0x18 | **accept** — 0x18 POD range copy; EAX/ECX/EDX ABI; return dest end |
| `aa_0044adc0` Phy_CPConnectionPair_ReleaseClear | **accept** — dual smart-slot Release + owner-out clear; stdcall `ret 4` |

---

## VA `0x00442b00` — sealed facts

1. **Body:** `0x00442b00`–`0x00442b3e` (63 B to final `RET` @ `0x00442b3e`).
2. **ABI:** EAX = dest*; ECX = begin*; EDX = end* (exclusive); plain `RET`; return **dest end** in EAX.
3. **Algorithm:** for each element, if dest≠null copy 6 dwords; always `begin+=0x18`, `dest+=0x18` until begin==end. Empty range: early `jz` → `ret` (EAX unchanged).
4. **Leaf:** no callees.
5. **Callers (8):** `FUN_00440f80` ×4, `FUN_00442760` ×4 — SkillSet vector insert/reallocate (`operator_new(n*0x18)`, max `0xaaaaaaa`).
6. **Name:** `SkillSet_UninitializedCopy_0x18` (Ghidra `FUN_00442b00`).
7. **Decompiler residual:** void return / phantom dest understates EAX dest+return.

### Gaps

- Product typedef for 0x18-byte entry fields.  
- Sibling stack-arg clone @ `0x00442b40` (not owned).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00442b00_SkillSet_UninitializedCopy_0x18.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00442b00_SkillSet_UninitializedCopy_0x18.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00442b00_FUN_00442b00.md` |
| Annotated | `docs/reconstruction/raw/aa_00442b00_FUN_00442b00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_UninitializedCopy_0x18.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00442b00.cpp` |
| Function | `docs/reconstruction/functions/aa_00442b00_FUN_00442b00.md` |
| Function named | `docs/reconstruction/functions/aa_00442b00_SkillSet_UninitializedCopy_0x18.md` |

---

## VA `0x0044adc0` — sealed facts

1. **Body:** `0x0044adc0`–`0x0044ae50` (145 B through final `ret 4`).
2. **ABI:** `__stdcall` 1 stack arg (pair*); `ret 4`; SEH (`fs:[0]`, handler `LAB_009bcaea`).
3. **Layout:** `+0`/`+8` owner-outs (clear only); `+4`/`+0xC` refcounted* (refcount at obj+4; Release-like at vtbl+8).
4. **Order:** clear `+8` → release `+0xC` → clear `+0` → release `+4` → `FUN_00437150` on both smart slots.
5. **Callee:** `FUN_00437150` @ `0x00437150` ×2 (rel32 sealed); usually no-op after inline clear.
6. **Callers (7):** `ClientSpecialEvent_TeleportIn_ctor`, `ClientSpecialEvent_Respawn_Update`, `FUN_0096d550`, `FUN_0096d5c0`, `FUN_0096dc80`, `FUN_009784f0`, `FUN_00855ff0`.
7. **Sibling:** `Phy_CPConnection_AssertConnectionPoint` @ `0x0044af00` binds same pair layout; fail path uses this teardown.
8. **Name:** `Phy_CPConnectionPair_ReleaseClear` (Ghidra `FUN_0044adc0`).
9. **Not** a heap free of the pair block.

### Gaps

- Exact product C++ type spelling.  
- `vtbl+8` English (Probable Release).  
- `FUN_00437150` dual residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044adc0_Phy_CPConnectionPair_ReleaseClear.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0044adc0_Phy_CPConnectionPair_ReleaseClear.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044adc0_FUN_0044adc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044adc0_FUN_0044adc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_CPConnectionPair_ReleaseClear.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044adc0.cpp` |
| Function | `docs/reconstruction/functions/aa_0044adc0_FUN_0044adc0.md` |
| Function named | `docs/reconstruction/functions/aa_0044adc0_Phy_CPConnectionPair_ReleaseClear.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00442b00` | Client SkillSet vector path — use POD memcpy stride 0x18; preserve EAX dest + return end; do not invent ctors. |
| `0044adc0` | Physics / special-event pair teardown — stdcall; release both smart slots; do not free pair here; align with `0x0044af00` bind layout. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
