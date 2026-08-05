# Function record: CVOGReaction_RemoveInventoryItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005721c0` |
| **Canonical name** | `CVOGReaction_RemoveInventoryItem` |
| **Address** | `0x005721c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean** — dual review not required this wave; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Remove up to `qty` of items matching clonebase CBID from a locked inventory. Partial stack reduce via vfunc+0x260 or full-remove into temp list then destroy.

## Signature

```c
int __thiscall CVOGReaction_RemoveInventoryItem(int pInventory, int cbid, int qty);
// returns quantity actually removed; 0 if cbid==-1 or qty<1
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005721c0_CVOGReaction_RemoveInventoryItem.md`
- Annotated: `docs/reconstruction/raw/aa_005721c0_CVOGReaction_RemoveInventoryItem.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGReaction_RemoveInventoryItem.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow / SEH frame | High |
| CBID match + stack qty vfuncs | High |
| Temp list structure | Probable |
