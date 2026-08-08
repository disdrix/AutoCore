# Function record: FUN_008ab0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab0a0` |
| **Canonical name** | `FUN_008ab0a0` |
| **Inferred name** | `Client_NpcMissionDialog_InitRuntimeFields_Inferred` |
| **Address** | `0x008ab0a0`–`0x008ab33d` (670 B / `0x29E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual sealed R11-035** (accept-with-gaps) — raw/annotated/clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |

## Alias

- Inferred: `Client_NpcMissionDialog_InitRuntimeFields_Inferred`
- Retired scaffold: `Named_CalleeOf_Mission_i_d_npc_xml_008ab0a0`

## Purpose

Mid-ctor **runtime field init / sentinel pack** for NPC mission-dialog host (`i_d_npc.xml`). Zeros widget/chrome pointers, writes `−1` into 8× response TFID pairs and 4× reward/chrome id pairs, nulls response widget slots, installs three default float4s, clears turn-in byte `+0x64c`.

## Signature (sealed)

```c
// thiscall ECX = NpcMissionDialogHost*; plain RET; leaf
void Client_NpcMissionDialog_InitRuntimeFields_Inferred(NpcMissionDialogHost *host);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.md`
- Annotated: `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialog_InitRuntimeFields_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008ab0a0.cpp`
- Named record: `docs/reconstruction/functions/aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md`
- A: `docs/reconstruction/reviews/A_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md`
- Report: `docs/agents/task-dual-ab-008ab0a0-r11-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `Client_NpcMissionDialogHost_Ctor_Inferred` (`FUN_008ac3f0`) @ `008ac505` | sole UNCONDITIONAL_CALL |
| DATA | vtbl `0x00a4a51c` + `0x3AC` @ `0x00a4a8c8` | method slot |
| Callees | *(none)* | leaf |

## Confidence

| Claim | Level |
|---|---|
| Control flow / body bounds | **High** |
| ECX thiscall ABI | **High** |
| Offset banks + float constants | **High** |
| Role: ctor field pack | **High** |
| Product/PDB English | **Open** (`_Inferred`) |
