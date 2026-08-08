# Dual A/B report — WQ9D-A OWN-ONLY (`aa_004cbdc0`, `aa_0051dd60`)

**Date:** 2026-08-04  
**Agent:** WQ9D-A OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004cbdc0`, `0x0051dd60`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth residual — skill-hash recreate/ctor chain.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cbdc0` SkillCNDHash_Recreate_Inferred | **accept-with-gaps** — recreate CF/ABI/strings/callers sealed; product English + nested destroy/alloc dual open |
| `aa_0051dd60` SkillCNDHash_Ctor_Inferred | **accept-with-gaps** — ctor CF/ABI/vtbl/sizeof/sole caller sealed; product English + full vtbl map open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; inventory type-merge, soft-abort-on-lock, owner-as-this, skill-id-as-log2 all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x004cbdc0` SkillCNDHash_Recreate_Inferred

1. **Body:** `0x004cbdc0`–`0x004cbe14` inclusive (**85 B** / `0x55`); `CC` pad after `ret 4`. Ghidra body end `004cbe14`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = skill CNDHash*  
   - stack `uint8_t log2`  
   - **void**  
   - **`ret 4`** (`5E C2 04 00`)

3. **Algorithm:**  
   - If lock byte `@+0x1d != 0`: log `"HashError:Recreate, already locked for traversal"` + `"VOG_DEBUG_STOP"` then **continue** (no abort).  
   - `FUN_004cba60` destroy old buckets.  
   - Store log2 `@+0x1c`; clear ordered tail `@+0x18` / head `@+0x14`; provisional count `@+8 = 1 << (log2 & 0x1f)`.  
   - `FUN_004cb410` alloc; post-condition `@+8` becomes **mask** `(1<<log2)-1`.

4. **Callers (2):**  
   - `Object_CreateOrRecreateSkillHash_Inferred` (`0x00518e30`) — `ECX=[owner+0x70]`, push caller log2.  
   - `FUN_004c8f00` @ `0x004c902c` — MI load hash, **imm log2=2**.

5. **Name:** `SkillCNDHash_Recreate_Inferred` — role High (string + CF + skill owner path); product class English **Inferred**.  
   Reject type-merge with inventory `CNDHash_Recreate` `0x004138d0` (EAX/BL custom ABI).

6. **Decompile ≡ bytes** for CF (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps — `004cbdc0`

1. Product/PDB class name for skill CNDHash.  
2. Full dual of nested `FUN_004cba60` / `FUN_004cb410` (not OWN).  
3. Bit-identity of freelist/node layout vs inventory CNDHash.  
4. Runtime / bit-exact open.

### Dual A/B — `004cbdc0`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` | **accept-with-gaps** |

### Files — `004cbdc0`

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cbdc0_FUN_004cbdc0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbdc0_FUN_004cbdc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_Recreate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cbdc0.cpp` |
| Function | `docs/reconstruction/functions/aa_004cbdc0_FUN_004cbdc0.md` |
| Function named | `docs/reconstruction/functions/aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` |

---

## Sealed facts — `0x0051dd60` SkillCNDHash_Ctor_Inferred

1. **Body:** `0x0051dd60`–`0x0051ddd2` inclusive (**115 B** / `0x73`); `CC` pad after `ret 4`. Ghidra body end `0051ddd2`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = raw `0x34`-byte block  
   - stack `uint8_t log2`  
   - **returns this in EAX**  
   - **`ret 4`**  
   - SEH `LAB_009a371b`

3. **Identity:** installs vtbl **`PTR_FUN_009ce1b8`** (`mov [esi], 0x009ce1b8`).

4. **Field init:**  
   - `+0x08 = 1 << (log2 & 0x1f)` provisional count  
   - byte `+0x1c = log2`  
   - byte `+0x1d = 0` (lock clear)  
   - zeros: `+0x04`, `+0x0c`, `+0x10`, `+0x14`, `+0x18`, `+0x20`, `+0x28`, `+0x2c`, `+0x30`  
   - **Odd (preserved):** **`+0x24` is not written**

5. **Post-init:** `FUN_004cb410` empty bucket alloc (same helper as recreate).

6. **Caller (1):** sole code xref — `Object_CreateOrRecreateSkillHash_Inferred` create path (`new(0x34)` → ctor → store `owner+0x70`).

7. **Name:** `SkillCNDHash_Ctor_Inferred` — role High; product English **Inferred**. Matches naming already used in parent dual B contract text.

8. **Decompile ≡ bytes** for CF (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps — `0051dd60`

1. Product English for class behind `009ce1b8`.  
2. Semantics of unwritten `+0x24` (pad vs latent field).  
3. Full vtbl method map / RTTI string if any.  
4. Dual of alloc helper `FUN_004cb410` / scalar dtor `FUN_0051de60` (not OWN).  
5. Runtime / bit-exact open.

### Dual A/B — `0051dd60`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` | **accept-with-gaps** |

### Files — `0051dd60`

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051dd60_FUN_0051dd60.md` |
| Annotated | `docs/reconstruction/raw/aa_0051dd60_FUN_0051dd60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051dd60.cpp` |
| Function | `docs/reconstruction/functions/aa_0051dd60_FUN_0051dd60.md` |
| Function named | `docs/reconstruction/functions/aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Object_LoadCloneBaseSkillTrio_Inferred (push log2=1)
  └─ Object_CreateOrRecreateSkillHash_Inferred (0x00518e30)
        ├─ existing +0x70 → SkillCNDHash_Recreate_Inferred (0x004cbdc0)   [OWN]
        └─ missing → new(0x34) + SkillCNDHash_Ctor_Inferred (0x0051dd60) [OWN]
FUN_004c8f00 also calls Recreate with log2=2 (creature MI path)
```

Parent duals for create-or-recreate and skill trio already sealed; this wave duals the **support recreate/ctor** residual called out in `ADV_wq009_spotcheck_0051b550_00518e30.md`.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cbdc0` | Skill hash resize must **always** tear down + rebuild when recreate is invoked — even if traversal-locked (log only). Use **thiscall** ECX=hash, not inventory EAX/BL ABI. After return, bucket select uses **mask** at `+8`, not raw count. |
| `0051dd60` | Skill hash object is **`sizeof 0x34`**, vtbl `009ce1b8`, log2 at `+0x1c`. Do not zero invent `+0x24`. Ctor returns this for store at owner skill-hash slot (`+0x70` on shared base). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/assembly_context).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); `_Inferred` where product English unproven.  
- Odd behavior preserved (lock continues; ctor skips `+0x24`).  
- **Terminal false.**
