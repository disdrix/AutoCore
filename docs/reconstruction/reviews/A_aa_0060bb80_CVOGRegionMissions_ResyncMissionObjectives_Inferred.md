# Review A (reconstruction fidelity): `aa_0060bb80` CVOGRegionMissions_ResyncMissionObjectives_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060bb80` |
| **VA** | `0x0060bb80` |
| **Body** | `0x0060bb80`–`0x0060be1e` |
| **Canonical name** | `CVOGRegionMissions_ResyncMissionObjectives_Inferred` |
| **Ghidra name** | `FUN_0060bb80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060bb80_CVOGRegionMissions_ResyncMissionObjectives_Inferred.md` |
| **System** | `missions-progression` |
| **Parent chain** | Sibling `CVOGRegionMissions_ctor` `0x0060b870`; inserts via `CNDHash_Insert` `0x0053c460` |
| **Dual status** | **Present** (W24-L first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_bulk_xrefs`. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Resync one mission's objectives** against the region-missions catalog:

1. ECX = `CVOGRegionMissions*`; stack = mission id; **`ret 4`**; AL status.
2. Lookup def in `*this` (mission-id hash); miss/null → 0.
3. DB cold-load mission rows (same helpers as ctor).
4. On matching catalog row: compare objective count (`def+0x130`) and identities; on mismatch remove objective-hash nodes (key `obj+0x10`) and re-insert via `CNDHash_Insert`; always `FUN_00546e40` materialize; free CoTaskMem.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060bb80_FUN_0060bb80.md` |
| Annotated | `docs/reconstruction/raw/aa_0060bb80_FUN_0060bb80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGRegionMissions_ResyncMissionObjectives_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0060bb80.cpp` |
| Function record | `docs/reconstruction/functions/aa_0060bb80_FUN_0060bb80.md` |
| Live decompile | `decompile_function` @ `0x0060bb80` (2026-07-29) |
| Entry bytes | `read_memory` 64 B — `sub esp,18`; save ECX; load `*this`; lookup; `ret 4` miss |
| Epilogue bytes | `read_memory` @ `0x0060be00` — CoTaskMemFree; `mov al,[esp+e]`; `ret 4` |
| Vtbl constant | `read_memory` @ `0x009cf02c` → `0x00537d10` |
| Peer ctor | dual `aa_0060b870` `CVOGRegionMissions_ctor` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI thiscall + ret 4 + AL status | **High** | entry/epilogue |
| `*this` = mission hash; lookup by missionId | **High** | entry + `CNDHash_LookupByKey` |
| Same DB trio as ctor | **High** | call list |
| Objective count @ `+0x130`, table @ `+0x13c` | **High** | body |
| Mismatch → remove + `CNDHash_Insert` | **High** | body + peer dual lists call @ `0060bd87` |
| Node vtbl `009cf02c` | **High** | body + `read_memory` |
| Class = `CVOGRegionMissions` | **High** | ctor peer layout + product file |
| English "ResyncMissionObjectives" | **Inferred** | structural |
| Static callers | **Open** | no CODE xrefs |
| Exact DB out-param binding | **Probable** | decompiler `unaff_EBX` |
| Runtime | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Null / lookup miss → 0 | Y | Y | Y |
| DB enter / fetch / leave | Y | Y | Y |
| Row match + obj compare | Y | Y | Y |
| Mismatch remove loop + lock strings | Y | Y | Y |
| FUN_00546e40 materialize | Y | Y | Y |
| Re-insert CNDHash_Insert | Y | Y | Y |
| CoTaskMemFree row + array | Y | Y | Y |
| Invented product branches | — | **None** | **None** |

---

## 5. Gaps

1. No static callers indexed — ownership / trigger path open.
2. Decompiler loses DB helper return regs (`unaff_EBX`, stack counts).
3. `FUN_00546e40` full signature residual.
4. Product English open beyond Inferred plate.
5. Runtime / bit-exact / differential — open.

**Verdict:** ABI + resync spine **High**. **accept-with-gaps.**
