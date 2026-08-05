# Review A (reconstruction fidelity): `aa_0054f3c0` SkillRuntime_PartialCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054f3c0` |
| **VA** | `0x0054f3c0`–`0x0054f42c` |
| **Canonical name** | `SkillRuntime_PartialCtor` (INFERRED; Ghidra `FUN_0054f3c0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (skill runtime partial zero-init) |
| **Counterpart** | `reviews/B_aa_0054f3c0_SkillRuntime_PartialCtor.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Partial constructor / zero-init** for a **`0x630`-byte skill runtime** object.

Called immediately after `operator_new(0x630)` in `CVOGReaction_ResolveSkillTargets` before **`REP MOVSD` of `0x18c` dwords** from def-map `node+0x10`. Also used by:

- `CVOGHBSkillBase_ctor`
- `FUN_00578830` / sibling skill-HB path
- `FUN_008422f0` (UI-adjacent skill helper)

**Not** a full C++ ctor of every field: it **zeros selected ranges**, then returns `this`. Full template payload is filled by the **caller copy** from the skill-def node (or other paths).

Convention: **`__fastcall` / thiscall ECX = buffer**; returns buffer in EAX (`mov eax, edx; pop edi; ret`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054f3c0_FUN_0054f3c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0054f3c0_FUN_0054f3c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0054f3c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054f3c0_FUN_0054f3c0.md` |
| Live Ghidra | `batch_decompile` / `analyze_function_complete` |
| Bytes | `read_memory` @ entry `8B D1` (`mov edx,ecx`); end `8B C2 5F C3` |
| Parent dual | `A_aa_0054c570_*` — `new 0x630` + this ctor + copy + rank |
| Rank sibling | `Skill_SetRankAndReevaluate` stores **`+0x5f6`** (not zeroed here; set after copy) |

---

## 3. Signature (sealed)

```c
// ECX = SkillRuntime* (0x630 bytes)
// returns SkillRuntime* (EAX = this)
SkillRuntime * __fastcall SkillRuntime_PartialCtor(SkillRuntime *this);
```

No stack args; plain **`ret`**.

---

## 4. Zero map (sealed from body)

| Offset | Width / count | Notes |
|---|---|---|
| `+0x5f0` | u32 = 0 | near rank `+0x5f6` (rank set later by SetRank) |
| `+0x184` … `+0x1a0` | 8× u32 (0x184,188,18c,190,194,198,19c,1a0) | dword block |
| `+0x1a4` | u8 = 0 | |
| `+0x1a5` | **0x100 dwords** (0x400 bytes) zeroed in loop | large buffer (name/text-like) |
| after loop | trailing u8 = 0 at `puVar2` | ends ~`+0x5a5` |
| `+0x5a6` | **0x10 dwords** (0x40 bytes) zeroed | second buffer |
| after | trailing u8 = 0 | |
| `+0x170` | u32 = 0 | |
| `+0x178` | u32 = 0 | |
| `+0x61c` | u8 = 0 | |

Returns `this`.

**Does not** zero entire `0x630` — caller **overwrite-copies** most fields from template (`0x18c` dwords from offset 0). Partial ctor clears runtime-only / string-like tails that might not be fully defined in template source, or re-clears volatile fields after placement.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero `+0x5f0` first | **Yes** |
| Dword block `+0x184..+0x1a0` | **Yes** |
| Byte + 0x100-dword wipe from `+0x1a5` | **Yes** |
| 0x10-dword wipe from `+0x5a6` | **Yes** |
| Zero `+0x170/+0x178/+0x61c` | **Yes** |
| Return this | **Yes** |
| No callees | **Yes** (leaf) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Skill runtime partial zero-init | **High** | parent materialize chain |
| ECX this / return this | **Confirmed** | bytes |
| Zero spans listed | **Confirmed** | decompile + clean |
| Full object size 0x630 | **High** | parent `new` + copy count |
| Field English names | **Open** | offsets only |
| Why selective vs memset whole | **Open** | product intent |
| Alias “CalleeOf_ResolveSkillTargets” exclusive | **Falsified** | 4 xrefs |

---

## 7. Gaps

1. Product field names for zeroed ranges (esp. `+0x1a5` 0x400-byte region).
2. Interaction with template copy order (ctor then copy may re-dirty zeros — **copy overwrites from 0**).
3. Other ctor paths that skip this helper.
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
