# Review A (reconstruction fidelity): `aa_004b85d0` NDSpecialFX_ClearChildLists_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b85d0` |
| **VA** | `0x004b85d0` |
| **Canonical name (Ghidra)** | `FUN_004b85d0` |
| **Proposed name** | `NDSpecialFX_ClearChildLists_Inferred` (**High** role; product symbol absent) |
| **Prior scaffold alias** | `Mission_Uses_Client_GetMissionCompleteAudioTable_004b85d0` — keyword only (audio path is one sub-step) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004b85d0_NDSpecialFX_ClearChildLists_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX lifetime |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Clear and free all intrusive child lists / maps on an NDSpecialFX host** without freeing the host itself or the owned blocks at `+0x3C`/`+0x60` (those are `FUN_004b99c0` TeardownCore).

Sequence on `fx` (ECX / `__fastcall`):

| Step | List / structure | Action |
|---|---|---|
| 1 | `+0x1E0` list, count `+0x1E4` | Walk payloads → `FUN_005be310(node[2])`; reset head links; count=0; free first node if not sentinel |
| 2 | `+0x204` list, count `+0x208` | Same pattern → `FUN_005be2f0(node[2])` |
| 3 | `+0x210` list, count `+0x214` | For each non-null payload: `FUN_005b85e0()` then `operator_delete` payload; reset list |
| 4 | `+0x1EC` list, count `+0x1F0` | If payload `+0x10B != 0`: pull audio keys `+0x120/+0x124/+0x128` → `Client_GetMissionCompleteAudioTable` + `FUN_00723b20` (stop matching sounds — dual `A_aa_00723b20`); then `operator_delete` payload |
| 5 | `+0x1F8` list, count `+0x1FC` | Delete payloads; reset list (audio-request list used by `004b6fc0` activate play) |
| 6 | Map rooted `+0x228`, size `+0x22C` | Walk nodes; free `node[4]` payloads; RB successor walk (`isnil @ +0x15`); then `FUN_004ba770` recursive free of tree or empty-header reset |

**Not** full teardown (`004b99c0` also frees `+0x3C`/`+0x60`, unregisters bit0, deletes map header), **not** play/activate.

Callers: `NDSpecialFX_LoadFromScriptName`, `FUN_004b99c0`, `FUN_004a6390` (LoadMasterFromXML flush), `FUN_004a2670`, `FUN_004a6790`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004b85d0` |
| Callers | `get_function_callers` (5 sites) |
| Parent dual | `A_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred.md` §1 step 3 |
| Audio stop dual | `A_aa_00723b20_CSoundManager_StopMatchingSounds_Inferred.md` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004b85d0` |
| Function record | `docs/reconstruction/functions/aa_004b85d0_FUN_004b85d0.md` |

**This pass:** live decompile; callers; sibling teardown. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// fastcall / thiscall via ECX
void __fastcall NDSpecialFX_ClearChildLists_Inferred(void *fx /* ECX */);
```

Multiple `operator_delete` sites marked **noreturn** by Ghidra — same false artifact as LoadFromScriptName / TeardownCore duals; control continues through subsequent list clears when deletes return.

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_005be310` | Per-node teardown for list `+0x1E0` |
| `FUN_005be2f0` | Per-node teardown for list `+0x204` |
| `FUN_005b85e0` | Payload dtor before free for list `+0x210` |
| `Client_GetMissionCompleteAudioTable` | Audio table lookup when mission-complete flag on `+0x1EC` payload |
| `FUN_00723b20` | `CSoundManager_StopMatchingSounds` |
| `FUN_004ba770` | Recursive RB/map node free (`isnil @ +0x15`) |
| `operator_delete` | Node / payload frees |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Clear `+0x1E0` / `+0x204` with typed helpers | Yes |
| Clear `+0x210` with dtor+delete | Yes |
| `+0x1EC` audio stop optional + delete | Yes |
| Clear `+0x1F8` | Yes |
| Map walk / free at `+0x228` | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| NDSpecialFX child-list clearer | **High** | Layout peers activate/teardown duals |
| List heads `+0x1E0/+0x204/+0x210/+0x1EC/+0x1F8` | **High** | body |
| Map header `+0x228` | **High** | teardown dual + this |
| Does **not** free host or `+0x3C`/`+0x60` | **High** | absent from body |
| Audio stop only when payload `+0x10B` set | **High** | branch |
| Per-list payload product types | **Tentative** | helpers unnamed |
| Safe re-entry when lists empty | **Probable** | LoadFromScriptName calls before TeardownCore |

---

## 7. Gaps / open

1. Formal names of `FUN_005be310` / `005be2f0` / `005b85e0`.
2. Exact payload layouts per list (audio list `0xC8` known from `004b6fc0` dual for `+0x1F8` only).
3. Whether map walk frees all nodes or relies on `004ba770` partial — decompiler splits empty vs non-empty.
4. Runtime leak verification not run.

**Verdict:** **accept-with-gaps** — list-clear CF High; payload type names open.
