# Function record: UI_MissionJournal_MSelectEntry_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ec0` |
| **Canonical name** | `UI_MissionJournal_MSelectEntry_Ctor_Inferred` |
| **Ghidra name** | `FUN_00829ec0` |
| **Address** | `0x00829ec0` |
| **Body range** | `0x00829ec0` – `0x00829f3b` (**123 B** / `0x7B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / mission journal (`missions-progression`) |
| **Calling convention** | stack `this`; returns `this`; **`ret 4`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ7R-E 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` |
| **Dual B** | `reviews/B_aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ7R-E) |

## Alias

- Ghidra: `FUN_00829ec0`
- Prior scaffold: `Mission_i_d_npc_2d_btn_mselect_xml_00829ec0`
- Reject domain-overfit: not a mission grant/complete/fail path

## Purpose

Construct mission-journal **mselect entry** widgets (`operator_new(0x510)` at callers). Base `NDUIContainerPanel_Ctor_Inferred`, subclass vtbl `PTR_FUN_00a74484`, clear tail fields used by chrome builder, selection sentinel `+0x500 = -1`, reload `i_d_npc_2d_btn_mselect.xml`.

## Signature

```c
MissionJournalMSelectEntry* UI_MissionJournal_MSelectEntry_Ctor_Inferred(
    MissionJournalMSelectEntry* self /*stack*/);
/* ret 4; returns self */
```

## Field tail (object size 0x510)

| Offset | Init | Peer role |
|---|---|---|
| `+0x4FC` | 0 | category-mode byte (`BuildMSelectChrome`) |
| `+0x4FD` | 0 | complete-flag byte |
| `+0x500` | `0xFFFFFFFF` | selection / mission-key sentinel |
| `+0x504` | 0 | mission button child |
| `+0x508` | 0 | title child |
| `+0x50C` | 0 | status child |

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | Sole: `Client_UpdateMissionJournal` `0x008ae130` — sites `008ae38f`, `008ae47d`, `008ae557`, `008ae666` |
| **Callees** | `FUN_00792d20` (`NDUIContainerPanel_Ctor_Inferred`), `NDUIWindow_ReloadInterface` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00829ec0_FUN_00829ec0.md` (+ WQ7R-E append)
- Annotated: `docs/reconstruction/raw/aa_00829ec0_FUN_00829ec0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_MissionJournal_MSelectEntry_Ctor_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00829ec0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00829ec0_FUN_00829ec0.md`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 4 ABI | **High** |
| Alloc size 0x510 at callers | **High** |
| XML skin string | **High** (literal @ `0x00a74978`) |
| Tail offsets shared with chrome peer | **High** |
| Journal entry-row role | **High** (sole caller + control ids `0x9c4f`) |
| Product C++ class name | **Inferred** |
| Runtime / bit-exact | **Open** |
