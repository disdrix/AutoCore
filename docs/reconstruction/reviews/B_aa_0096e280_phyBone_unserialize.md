# Review B (skeptical / adversarial): `aa_0096e280` phyBone_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e280` |
| **VA** | `0x0096e280` |
| **Canonical name** | `phyBone_unserialize` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_0096e280_phyBone_unserialize.md` |
| **System** | `physics / phy` |
| **Verdict** | **accept-with-gaps** on CF/tag/offsets; **reject** over-named field English, “always binary”, “returns void”, “owns skeleton” |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Whole skeleton / mesh unserialize” | **Falsified** — single bone; skeleton is caller `FUN_0096b930` (PSKE) looping bones |
| “Only binary assets” | **Falsified** — dual path on `reader+0x4044` (text int/float readers) |
| “Four float fields” / “four int fields” | **Falsified** — text path proves **3× int32 + 1× float32** |
| “Always returns 0 on success” | **Partial** — success is **OR of status bits**; any field/nested error propagates non-zero; only hard fail is `0xffffffff` for bad tag/version |
| “Creates the shared data always from empty” | **Overclaim** — `FUN_00449dc0` installs a 0x90 object on `EBX+4`; exact slot vs `this+0xf4` not image-proven without EBX setup from caller; nested call still uses `*(this+0xf4)` |
| “hkQsTransform is inlined in PBON body” | **Falsified** — body reads four scalars then **delegates** nested BDAT via `phyBoneSharedData_unserialize` |
| Product names parent/child/mass for `+0x148..` | **Unproven** — offsets High, English Tentative |
| “No error logging” | **Falsified** — invalid TAG / version log via `vog_LogMessage` |

---

## 2. Decompiler hazards

| Decomp artifact | Reality / stance |
|---|---|
| `unaff_ESI` as `this` | **Agree High** — field stores and nested shared load; caller loop treats vector elements as bones |
| `param_1` only formal | Reader; `this` not in signature display — convention is member unserialize with ESI this |
| `FUN_00449dc0()` no args | Uses **unaff_EBX** — do not invent “no object”; object is EBX-relative |
| `FUN_0096de80()` no args | Uses **in_EAX** as bone — post-condition is copy from `*(bone+0xf4)` |
| `phyBoneSharedData_unserialize` single arg display | Nested BDAT on shared object; sibling plate has fuller signature — **do not re-own sibling VA** |
| Void return (signature table elsewhere) | **Reject** — body returns status uint / `0xffffffff` |
| Clean plate double-spaced raw dump | CF still ≡ raw; not a semantic rewrite hazard |

---

## 3. Layout / semantics challenges

| Challenge | Response | CF |
|---|---|---|
| Is `+0x154` really float? | Text path `FUN_00767fd0` sscanf `%f` / “Expected float32”; binary is still 4-byte load | **High** type from text path |
| Are ints bone indices? | Caller only writes **`+0x144` index** after unserialize — body fields may be hierarchy IDs or flags; **not sealed** | Offsets High / names Tentative |
| Tag endianness PBON vs NOBP | Immediate is `0x50424f4e`; plate documents file bytes `NOBP` — both consistent LE fourCC | **High** |
| Does fail path still leave scope? | Yes — both success and fail clear SEH and call leave when `local_18` | **High** |
| Nested transform “required for correct geo” | Plate / shared sibling claim — **Probable** product impact; not re-proven from this VA alone | Probable (external) |
| Single caller only? | Ghidra xrefs: **one** unconditional call from `FUN_0096b930` | **High** (static) |

---

## 4. Surviving contract (minimal)

```c
// Member unserialize: ESI = phyBone*, param_1 = stoChunkReader*
// PBON (0x50424f4e) version 1 only; else log + return 0xffffffff
// reader+0x4044==0 → binary i32,i32,i32,f32 into this+0x148..+0x154
// else             → text  i32,i32,i32,f32 into same
// then ensure/shared path + phyBoneSharedData_unserialize(*(this+0xf4))
// then copy transform from shared into this+4..+0x28; this+0x140 = -1
// return OR(read statuses, nested status)
```

Do **not** treat as:
- skeleton container / mesh geometry unserialize
- inline TADB body without nested call
- named hierarchy fields without further evidence
- success always zero

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| Tag PBON + version 1 gate | **Agree** |
| Binary vs text via `+0x4044` | **Agree** |
| Offsets `+0x148..+0x154` | **Agree** |
| Nested shared `@ +0xf4` | **Agree** |
| `FUN_0096de80` copy + `+0x140=-1` | **Agree** CF |
| Field English open | **Agree** — attack any hard names |
| Caller phySkeleton loop | **Agree** — single xref |
| `FUN_00449dc0` installs shared-like | **Agree with caution** — EBX slot vs `+0xf4` relationship not fully sealed |
| accept-with-gaps | **Agree** |

---

## 6. Residual (honest)

1. Product names for four PBON body fields.
2. Exact type / vtable of `FUN_00449dc0` object; EBX base relative to bone.
3. English for `+0x140` sentinel.
4. Named binary/text readers.
5. Runtime confirmation on retail `.phy` / text dumps.
6. Serialize twin symmetry (if present) not dualed this pass.

---

## 7. Verdict

### **accept-with-gaps**

CF, tag/version, dual binary/text path, field offsets, nested shared call, and post-copy helper are **sealed**. Reject whole-skeleton conflation, all-float/all-int field maps, and void-return. Dual A is acceptable with field English and `FUN_00449dc0` typing left open.
