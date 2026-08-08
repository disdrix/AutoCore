# Review B (adversarial): `aa_0061b6f0` CVOGHBSkill_SharedOnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061b6f0` |
| **VA** | `0x0061b6f0`–`0x0061b955` |
| **Canonical name** | `CVOGHBSkill_SharedOnHeartBeat_Inferred` |
| **Ghidra symbol** | `FUN_0061b6f0` |
| **Review date** | `2026-08-04` (WQ9D-C OWN-ONLY dual B) |
| **Reviewer role** | Adversarial reconstruction review (Path B) |
| **Counterpart** | `reviews/A_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, callers/xrefs, COL/type_info (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## Attack surface / falsification attempts

| Hypothesis | Result |
|---|---|
| This is Virus-only helper, not a general method | **Falsified** — 9 DATA vtbl installs; Virus is a **caller** that overrides OnHB and calls this. RTTI shows Chain / InverseChain / Aggregate share the slot. |
| Slot is TryFire not OnHeartBeat | **Weakened / Probable OnHB** — same relative slot as Virus OnHB (`0061fdf0` at sibling vtbl+0x08). Path A name as SharedOnHeartBeat matches consumer dual language (“shared pulse”). Residual: base class plate name open. |
| Status `0x10` is “Health skill id” only | **Open English** — dword is **0x10**; string `"Health"` is adjacent at `+8` but may be neighboring table entry, not this constant’s label. Gate semantics sealed; English not. |
| Always applies all effects | **Falsified** — each effect is independently gated (nonzero short/float/bit); outer gate can skip entire cascade. |
| Hard-stop is silent no-op | **Falsified** — `vtbl+0x18(1,1)` on flag8 miss path. |
| Leaf / no callees | **Falsified** — large worker with 10+ callees. |
| Confuse with cast managers | **Falsified** — post-cast HB tick; no RequestCast / LocalCastValidate. |

---

## Residual risks

1. Product field English / effect taxonomy incomplete.  
2. Nested duals (`005787a0`, heat/HP/shield/impulse leaves) residual.  
3. Decompiler may show duplicated flag8 arms that are one real path (Probable).  
4. Full vtbl→RTTI census of all 9 DATA hosts not expanded beyond sample.  
5. Runtime / stacking / bit-exact open.

---

## Agreement with Path A

A's CF seal, ABI, multi-class vtbl role, constant `0x10`, and accept-with-gaps are supported. No CF reject. Naming as SharedOnHeartBeat is **Inferred** but consistent with Virus residual language and vtbl alignment.

**Verdict:** **accept-with-gaps**
