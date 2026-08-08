# Function record: StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409880` |
| **Canonical name** | `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` |
| **Ghidra name** | `FUN_00409880` |
| **Address** | `0x00409880` |
| **Body range** | `0x00409880` – `0x004098c4` (**69 B** / `0x45`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / MSVC `_Tree` node construct |
| **Calling convention** | __usercall: node@&lt;eax&gt;, value*@&lt;ecx&gt;, left@&lt;edx&gt;, parent/right/color stack; **`ret 0xc`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9J-H 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` |
| **Dual B** | `reviews/B_aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9J-H) |

## Alias

- Ghidra: `FUN_00409880`
- Reject: `Named_CalleeOf_*Client_*` scaffold plate
- Reject: freelist/CNDHash init
- Reject: merge with thiscall twin `FUN_004098d0`
- Reject: naming as buynode (no alloc)

## Purpose

MSVC-style **tree node construct** (no `operator_new`) for the **isnil@+0x29 / Val24** family using **EAX-this** usercall ABI:

1. left/parent/right → +0/+4/+8
2. six dwords from value* → +0x10
3. color → +0x28; isnil → +0x29 = 0

Sole caller buynode `FUN_00404180` supplies node from `operator_new(0x30)`.

## Signature

```c
/* __usercall node@<eax>(value*@<ecx>, left@<edx>, parent, right, color); ret 0xc */
void StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred(
    NodeIsnil29_Val24* node,
    const uint32_t* value6,
    NodeIsnil29_Val24* left,
    NodeIsnil29_Val24* parent,
    NodeIsnil29_Val24* right,
    uint8_t color);
```

## Behavioral summary

```
node.left/parent/right = left/parent/right
node.val[0..5] = value6[0..5]
node.color = color
node.isnil = 0
return  ; RET 0xC
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers** | `FUN_00404180` @ `0x004041d6` (SEH new 0x30 buynode; used by insert `FUN_004069f0`) |
| **Twin** | `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` (`0x004098d0`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409880_FUN_00409880.md`
- Annotated: `docs/reconstruction/raw/aa_00409880_FUN_00409880.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00409880.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00409880_FUN_00409880.md`
- Report: `docs/agents/task-dual-ab-00409880-004098d0-wq9jh-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + store map + RET 0xC | **High** |
| EAX/ECX/EDX ABI | **High** |
| Val24 / isnil29 family | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
