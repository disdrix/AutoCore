# Dual A/B report — W27-M OWN `aa_00515520` + `aa_006297e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-M  
**Scope:** VAs `0x00515520`, `0x006297e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` (+ xrefs/callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00515520` CVOGObject_ComputeOutcomeRolls_Inferred | **accept** — ABI ret 0x28 + virtual-only + 6-channel roll spine sealed; arg-map/product English residual |
| `aa_006297e0` Phys_CommitPairListStorage_Inferred | **accept** — ABI ret 0x10 + dual-list gate + pair buffer layout sealed |

---

## VA `0x00515520` — sealed facts

1. **Body:** `0x00515520`–`0x00516706` (**4583 B**); prologue `sub esp, 0xC0`.
2. **ABI:** **thiscall**; ECX = object; **ret 0x28** (10 stack dwords); returns **int**.
3. **Dispatch:** **26 DATA** vtable installs; **0 CODE** callers — pure virtual.
4. **Spine:** validity gates → level/theory/linked gather → **6-channel** short rolls (RandomUnitScalar or seed table) → optional reaction lists (param_3/param_4) → clamp return → optional FUN_00535ed0.
5. **Constants (read_memory):** `_DAT_009cdf80` = **0.004f**; `DAT_00af1b70` = **0.5f**; `DAT_009cdf9c` first four **1.35 / 1.15 / 1.0 / 1.23**.
6. **Callees:** GetLinkedActorLevel, Theory, TFID helpers, ResolveUseObjectPending, RandomUnitScalar, CNDDoubleList helper, ceil.
7. **Name:** `CVOGObject_ComputeOutcomeRolls_Inferred` (Ghidra `FUN_00515520`).
8. **Caveat:** shared float labels (e.g. g_flMultiKillCountBlend) are pool 0.1f — not product multi-kill evidence. Decompiler unaff_* noise.

### Gaps

- Product English / exact award type.  
- Complete 10 stack formals.  
- Predicate labs not OWN.  
- Runtime / bit-diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00515520_CVOGObject_ComputeOutcomeRolls_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00515520_CVOGObject_ComputeOutcomeRolls_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00515520_FUN_00515520.md` |
| Annotated | `docs/reconstruction/raw/aa_00515520_FUN_00515520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_ComputeOutcomeRolls_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00515520.cpp` |
| Function | `docs/reconstruction/functions/aa_00515520_FUN_00515520.md` |
| Function named | `docs/reconstruction/functions/aa_00515520_CVOGObject_ComputeOutcomeRolls_Inferred.md` |
| Live dump | `docs/reconstruction/tmp/w27m_00515520_live_decomp.txt` |
| Scratch | `docs/reconstruction/tmp/a_00515520.md` |

---

## VA `0x006297e0` — sealed facts

1. **Body:** `0x006297e0`–`0x00629983` (**420 B**); pad `CC` from `0x00629984`.
2. **ABI:** **thiscall**; ECX = pair-storage host; 4 stack args; **void**; **ret 0x10**.
3. **Gate:** enter only if listA_count != 0 || listB_count != 0.
4. **Semantics:** dual FUN_006cad30 → FUN_0055f520 → iterators on +0x68/+0x6c (stride **0x10**) → FUN_006caaa0 → copy/grow (allocator tag **0x12**) → writeback → FUN_0055f590.
5. **Callers (CODE):** WorldObj_BindLinks (0055fa40) x2, WorldObj_UnbindLinks (0055fbf0) x2, island FUN_00629d90 x1.
6. **Name:** `Phys_CommitPairListStorage_Inferred` (Ghidra `FUN_006297e0`; preferred over prior Named_CalleeOf_...CVOGSpawnPoint scaffold).
7. **Decompile equiv bytes** for CF (live 2026-07-29 equiv raw 2026-07-23).

### Gaps

- Product English for host class.  
- List payload types at BindLinks vs island.  
- Nested 006caaa0 / 006cad30 not OWN.  
- Runtime / bit-diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006297e0_Phys_CommitPairListStorage_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006297e0_Phys_CommitPairListStorage_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006297e0_FUN_006297e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006297e0_FUN_006297e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_CommitPairListStorage_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006297e0.cpp` |
| Function | `docs/reconstruction/functions/aa_006297e0_FUN_006297e0.md` |
| Function named | `docs/reconstruction/functions/aa_006297e0_Phys_CommitPairListStorage_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006297e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00515520` | Object virtual outcome rolls: **ret 0x28**, 6 channels, optional reaction flags. Do **not** merge with CVOGCombat_CalculateAndAwardKillXP (`004d80b0`). Do **not** invent multi-kill from shared float pool names. |
| `006297e0` | Pair-list commit for **bind/unbind** and **island** paths. Keep dual-list API, stride **16**, allocator tag **0x12**, no-op when both counts zero. Closes residual from W26-E BindLinks dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs/callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence (`_Inferred` only).  
- Avoided bare `undefined4` in clean (`uint32_t`).
