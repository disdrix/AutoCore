# Function record: StdTree_Buynode_Val12_EsiValue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046c6c0` |
| **Canonical name** | `StdTree_Buynode_Val12_EsiValue` (Inferred) |
| **Ghidra name** | `FUN_0046c6c0` |
| **Address** | `0x0046c6c0` |
| **Body range** | `0x0046c6c0`–`0x0046c702` exclusive (**66** B / `0x42`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map node allocation |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + ESI ABI sealed; product demangle open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md`, `reviews/B_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` (2026-07-29 W28-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0046c6c0`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_0046c6c0` (legacy xref scaffold — **narrow**)
- Twin (stack value*): `StdTree_Buynode_Val12` `aa_005ae220` @ `0x005ae220` — **different ABI**

## Purpose

Allocate and initialize one Val12 red-black tree node (`operator_new(0x1c)`): three links from stack args, three-dword value from **ESI**, color byte from stack, isnil=0. Return pointer or null on OOM.

## Signature

```c
// ESI = const uint32_t value3[3]  (implicit register arg)
StdTreeNode_Val12* __stdcall StdTree_Buynode_Val12_EsiValue(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    uint8_t color);
// RET 0x10; EAX = node* | null
```

## Algorithm

1. `node = operator_new(0x1c)`; if null return null.
2. `node->{left,parent,right} = stack args`.
3. Copy `ESI[0..2]` → `node+0x0c`.
4. `node->color = color`; `node->isnil = 0`.
5. Return node in EAX.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0046c6c0_FUN_0046c6c0.md`
- Annotated: `docs/reconstruction/raw/aa_0046c6c0_FUN_0046c6c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val12_EsiValue.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0046c6c0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0046c6c0-00573810-w28t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `operator_new` only |
| **Callers** | `FUN_0043c2e0` @ `0x0043c348`; `FUN_0044a8c0` @ `0x0044a928` (Map_TreeInsertAndRebalance_Val12_EsiBuy, W27-P) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `ret 0x10` + 4 stack args | **High** |
| ESI value source | **High** |
| Node layout + isnil=0 | **High** |
| EAX return (not void) | **High** |
| Distinct from `005ae220` | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Stack-arg twin: `aa_005ae220` `StdTree_Buynode_Val12` (W24-I **accept**)
- Primary consumer dual: `aa_0044a8c0` `Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred` (W27-P)
