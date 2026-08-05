# Review B (skeptical / adversarial): `aa_0052d8b0` Clear mission staging tree

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052d8b0` |
| **VA** | `0x0052d8b0` |
| **Canonical name** | `FUN_0052d8b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_0052d8b0_ClearMissionStagingTree.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** on CF/layout; **reject** “always destroys objects”, “tree only at +0x50c”, product names |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Always destroys staged world objects” | **Falsified** — destroy gated on `flag != 0`; **all 8 xrefs push 0** |
| “Active mission journal clear (`+0x540`)” | **Falsified** — only map at **`+0x508` / end `+0x50c`** (staging sibling of `FUN_0052c700`) |
| “Only walks `+0x50c` as map root” | **Partial** — `+0x50c` is **header/end**; map **object** for helpers is **`+0x508`** |
| “GiveMission / CompleteObjective body” | **Falsified** — those **call** this after their own insert work |
| “Dialog UI reset” | **Falsified** — map clear only; UI is separate (`RecvNpcMissionDialog` stages then shows) |
| Product name `ClearMissionRewardStaging` as exclusive | **Unproven** — used for dialog offer clear (`-1`), grant cleanup (keyed), ctor/dtor full clear |
| Decomp “full clear is `erase(right); delete(root)` once” | **Incomplete** — image shows **loop** free + header reset; Ghidra noreturn on `operator_delete` truncates |

---

## 2. Decompiler hazards

| Decomp artifact | Reality |
|---|---|
| Missing map `this` on lower_bound/erase | Asm `LEA ECX,[char+0x508]` |
| Missing resolve `this` | Asm `MOV ECX,[sectorMap+0xe4e8]` before `ResolveObjectTarget` |
| `void` ok | **Agree** — no meaningful return (epilogue `ret 8` only) |
| Full-clear “does not return” | **False** — falls through to header zero-size reset |
| `FUN_00538780(&param_2, …)` first arg meaning | Stack dummy/out; real map is ECX — do not invent semantics for `&param_2` |

---

## 3. Layout / semantics challenges

| Challenge | Response | CF |
|---|---|---|
| Is this “reward” only? | Callers: dialog full clear, GiveMission keyed clear, CompleteObjective keyed, EndQuest full, ctor/dtor full — **shared staging map**, not reward-only | High multi-use |
| 4 pairs vs 8 COIDs | Upsert stores 12 dwords; destroy walks **4×2 dwords** at `+0x18` — count sealed; “TFID” English only Probable | High count |
| Exact find vs lower_bound erase-wrong-key | Sibling `FUN_00538a40` returns end unless `key <= probe` after lower_bound shape ⇒ exact; erase only after non-end | High (sibling) / not re-byte-proved here |
| `char+0xcc4` list role | `FUN_005875c0` unlinks matching ptr; product name open | High unlink CF |
| `destroyFlag` ever true? | **No live xref** in 8 sites; branch is real code — residual | High unused-from-xrefs |

---

## 4. Surviving contract (minimal)

```c
// thiscall Character*; ret 8
void MissionStagingMap_Clear(Character* ch, char destroyFlag, int missionId);
// map @ ch+0x508; end @ ch+0x50c; size @ ch+0x510
// missionId == -1  → walk all nodes; free all; size=0
// missionId != -1  → find key; if hit optional destroy + erase one; else nop
// destroyFlag == 0 → map structure only (all current callers)
// destroyFlag != 0 → for each of 4 payload pairs: Resolve(bGlobal=1) → unlink ch+0xcc4 → FUN_004d4790
```

Do **not** treat as:
- active-mission hash teardown (`+0x540` / EndQuest body does that separately)
- eligibility / GiveMission itself
- guaranteed object destruction on clear

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| Map `+0x508` / end `+0x50c` / size `+0x510` | **Agree** — image |
| `ret 8`, thiscall | **Agree** |
| 4-pair walk at `node+0x18` | **Agree** |
| All xrefs `flag=0` | **Agree** — attack any “always destroy” wording |
| Product English open | **Agree** |
| Full-clear loop vs decomp | **Agree** A’s correction; keep decomp hazard documented |
| Sibling 12-dword payload | **Agree** shared geometry with `aa_0052c700` |

---

## 6. Residual (honest)

1. Product / export name.
2. Live path for `destroyFlag != 0`.
3. Precise English for payload[0..7] (COID list vs TFID pairs).
4. Names for erase/free/list helpers.
5. Runtime observation of size `+0x510` across dialog → grant → end.

---

## 7. Verdict

### **accept-with-gaps**

CF, offsets, dual mode (`-1` vs key), and caller arg patterns are **sealed**. Reject object-destruction-as-default and active-journal conflation. Dual A is acceptable with product name and destroyFlag use left open.
