# Function record: StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004088f0` |
| **Canonical name** | `StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred` |
| **Ghidra name** | `FUN_004088f0` |
| **Address** | `0x004088f0` |
| **Body range** | `0x004088f0` – `0x00408979` (**138 B** / `0x8A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / MSVC `_Tree` empty-node buy |
| **Calling convention** | cdecl; no args; **EAX = node\***; **`ret 0`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9H-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` |
| **Dual B** | `reviews/B_aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-I) |

## Alias

- Ghidra: `FUN_004088f0`
- Reject: `CNDHash_FreelistPop_Node0x28` identity — different family (aligned slab freelist)
- Reject: isnil29 Val24 buynode (`00407e30` / `005a2de0`) — different size/layout/ABI
- Reject: full value buynode `00408990` — takes 5 args + construct helper
- Reject: chain-of-caller GiveItemByCbid scaffold plate

## Purpose

MSVC-style **empty tree node buy** for the **isnil@+0x21 / size 0x28** instantiation:

1. SEH + `operator_new(0x28)`
2. Zero left/parent/right
3. color@+0x20 = 1; isnil@+0x21 = 0
4. Return node\* in EAX

Callers promote the node to **head sentinel** (isnil=1, circular links, size=0).

## Signature

```c
struct NodeIsnil21_Size28* StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred(void);
/* cdecl; ret 0; EAX = node* | null */
```

## Behavioral summary

```
node = operator_new(0x28)
if node:
  node.left = node.parent = node.right = 0
  node.color = 1
  node.isnil = 0
return node
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `operator_new` |
| **Callers** | `FUN_00405560`, `FUN_00405d00`, `FUN_00406100` (tree-shell ctors); `FUN_00501970` (Vehicle map member head) |
| **Twins** | `FUN_00408a30` empty isnil29/size0x30; value buynode `FUN_00408990` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004088f0_FUN_004088f0.md`
- Annotated: `docs/reconstruction/raw/aa_004088f0_FUN_004088f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004088f0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004088f0_FUN_004088f0.md`
- Report: `docs/agents/task-dual-ab-00408880-004088f0-wq9hi-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + new(0x28) + color/isnil offsets | **High** |
| cdecl + EAX return | **High** |
| Head-init caller pattern | **High** |
| Product demangle / Val20 type | **Inferred** |
| Runtime / bit-exact | **Open** |
