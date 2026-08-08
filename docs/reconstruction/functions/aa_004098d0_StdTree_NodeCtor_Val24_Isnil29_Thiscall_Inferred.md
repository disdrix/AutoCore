# Function record: StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004098d0` |
| **Canonical name** | `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` |
| **Ghidra name** | `FUN_004098d0` |
| **Address** | `0x004098d0` |
| **Body range** | `0x004098d0` – `0x0040991e` (**79 B** / `0x4F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / MSVC `_Tree` node construct |
| **Calling convention** | **__thiscall**; ECX=this; 5 stack args; **`ret 0x14`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9J-H 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` |
| **Dual B** | `reviews/B_aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9J-H) |

## Alias

- Ghidra: `FUN_004098d0`
- Reject: chain-of-caller scaffold plate
- Reject: freelist/CNDHash init
- Reject: merge with EAX twin `FUN_00409880`
- Reject: naming as buynode (no alloc; buy is `00407e30`)

## Purpose

MSVC-style **tree node construct** (no `operator_new`) for the **isnil@+0x29 / Val24** family using **thiscall**:

1. left/parent/right → +0/+4/+8
2. six dwords from value* → +0x10
3. color → +0x28; isnil → +0x29 = 0

Sole caller: dualed `StdTree_Buynode_Val24_Isnil29_Inferred` (`0x00407e30`).

## Signature

```c
void __thiscall StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred(
    NodeIsnil29_Val24* this,
    NodeIsnil29_Val24* left,
    NodeIsnil29_Val24* parent,
    NodeIsnil29_Val24* right,
    const uint32_t* value6,
    uint8_t color);
/* ret 0x14 */
```

## Behavioral summary

```
this.left/parent/right = left/parent/right
this.val[0..5] = value6[0..5]
this.color = color
this.isnil = 0
return  ; RET 0x14
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers** | `StdTree_Buynode_Val24_Isnil29_Inferred` / `FUN_00407e30` @ `0x00407e88` (WQ9F-B) |
| **Twin** | `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` (`0x00409880`) |
| **Store peer** | inlined path inside `FUN_005a2de0` (no-SEH buynode) — do not merge |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004098d0_FUN_004098d0.md`
- Annotated: `docs/reconstruction/raw/aa_004098d0_FUN_004098d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004098d0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004098d0_FUN_004098d0.md`
- Report: `docs/agents/task-dual-ab-00409880-004098d0-wq9jh-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + store map + RET 0x14 | **High** |
| thiscall ABI | **High** |
| Val24 / isnil29 family | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
