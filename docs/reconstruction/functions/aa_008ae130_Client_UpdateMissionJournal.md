# Function record: Client_UpdateMissionJournal

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae130` |
| **Canonical name** | `Client_UpdateMissionJournal` |
| **Address** | `0x008ae130` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Human-refined + residual dual sealed** (2026-07-29); not complete |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual status** | A/B accept-with-gaps; id-vector residual closed static |

## Purpose

Refresh mission journal UI when dialog state==3. Walks `char+0x50c` tree, partitions each mission id into Active vs New stack vectors via `char+0x540` hash probe (`[node+0x8]!=0` → Active), builds panels with multi-select entry widgets. UI only — no grant/fail/network.

## Signature (refined)

```c
void __thiscall Client_UpdateMissionJournal(void *this, int *pContext);
// dialog host primarily in EBX; state at +0x648 must be 3
```

## Key callees (residual-sealed)

| Address | Name / role |
|--------:|-------------|
| `0x004149d0` | `CVOGReaction_FailMissionNotify` — **Vector_PushDword** at this site |
| `0x00568200` | Tree/list **iterator++** (`__fastcall`); not id fill |
| `0x00829ec0` | Entry widget ctor `0x510`; XML `i_d_npc_2d_btn_mselect.xml` |
| `0x0053fff0` | Lazy mission-def table getter |
| `0x00547920` | Mission UI populate (mode 0) |

## Partition (assembly)

```
hash hit && *(hashNode+0x8) != 0  → Active vector
else                              → New vector
```

Widget control ids: Active `i+0x9c4f`; New `activeCount+0x9c4f+i`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ae130_Client_UpdateMissionJournal.md`
- Annotated: `docs/reconstruction/raw/aa_008ae130_Client_UpdateMissionJournal.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UpdateMissionJournal.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008ae130_Client_UpdateMissionJournal.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008ae130_Client_UpdateMissionJournal.md`
- Scratch: `tmp/a_008ae130.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Active/New partition (assembly) | High |
| FUN_00568200 = iterator++ | High |
| FailMissionNotify = push only here | High |
| Hash `+0x8` product name | Probable |
| Types / UI vtable names | Probable / open |
| Runtime / bit-exact | Open |
