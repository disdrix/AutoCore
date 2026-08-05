# Review A (reconstruction fidelity): `aa_004a04f0` MissionTree_InorderCollectMediaPreloads_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a04f0` |
| **VA** | `0x004a04f0`–`0x004a057a` exclusive (**138 B**) |
| **Canonical name** | `MissionTree_InorderCollectMediaPreloads_Inferred` |
| **Ghidra name** | `FUN_004a04f0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-C) |
| **Counterpart** | `reviews/B_aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` |
| **System** | mission tree inorder → media preload collect |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full body + parent call sites) + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Inorder-walk a tree of mission-host payloads and invoke sealed `MissionHost_CollectMediaPreloads` (`0x004b88e0`) once per node with the parent’s four stack formals (unused + three independent flags).

Closes W32-H residual: tree-walk ECX wiring for `004b88e0`’s map parent; bridges Object/Sound/Physics CollectAll* preload plates.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-C append) | `docs/reconstruction/raw/aa_004a04f0_FUN_004a04f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a04f0_FUN_004a04f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionTree_InorderCollectMediaPreloads_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004a04f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` |
| Per-node dual | W32-H `aa_004b88e0` |
| Graphics parent | W32-H `aa_004f1ff0` Object_CollectAllGraphicsPreloads |
| Live | decompile ≡ scaffold; `C2 10 00`; 5 callers / 1 callee |

---

## 3. Signature (sealed)

```c
// thiscall; RET 0x10
void MissionTree_InorderCollectMediaPreloads_Inferred(
    TreeHolder* holder /*ECX*/,
    uint32_t unused,
    uint32_t flag_media_strings,
    uint32_t flag_mission_audio,
    uint32_t flag_obj_paths);
```

| Slot | Source | Conf |
|---|---|---|
| holder | **ECX** thiscall | **High** |
| 4 stack formals | Stack[4..10]; forwarded to `004b88e0` | **High** |
| cleanup | `C2 10 00` | **High** |
| return | void | **High** |

Parent ECX evidence: CollectAllSoundPreloads site loads **`mov ecx,[reg+0x88]`** then `test ecx` / push flags / call. Graphics/physics same `obj+0x88` gate in decompile; mission apply uses **embed** `iVar+0x44` / stack local as holder.

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| head = `*(*holder + 4)`; begin = `*head`; empty iff begin==head | bytes | **High** |
| loop: payload `[node+0x10]` → ECX; call `004b88e0` | bytes `8B 4E 10` + call | **High** |
| inorder successor left/parent/right + nil @ +0x15 | decompile ≡ bytes | **High** |
| until node==head; RET 0x10 | **Yes** | **High** |

### Parent flag triples (stack after holder)

| Parent | Plate | Flags (media, audio, paths) |
|---|---|---|
| `004f1ff0` | CollectAllGraphicsPreloads | `(1,0,0)` |
| `004ebf50` | CollectAllSoundPreloads | `(0,1,0)` |
| `004ec7b0` | CollectAllPhysicsPreloads | `(0,0,1)` |
| `00542e20` / `00542790` | mission residual | `(1,1,1)` |

---

## 5. Machine bytes (`read_memory`)

Full body hex (138 B) — raw W37-C append.

Entry: `51 8B 01 8B 40 04 56 8B 30 3B F0 …`  
Call: `8B 4E 10 55 53 57 E8 C0 83 01 00` → `004b88e0`.  
Epilogue: `5F 5D 5B 5E 59 C2 10 00`. Pad `CC` @ `0x004a057a`.

---

## 6. Gaps

- Product English for tree/holder/node (no string/RTTI on this VA).
- Precise MSVC `_Tree` layout for holder first indirection.
- Whether +0x15 is stock `_Isnil` vs packing-specific nil-gate (behavior sealed either way).
- Runtime / bit-exact / differential.

---

## Verdict

**accept-with-gaps** — ABI/walk/callee/flag-forward sealed; product type names open.
