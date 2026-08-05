# Function record: AssPreloader_DrainAcRingToTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970fc0` |
| **Canonical name** | `AssPreloader_DrainAcRingToTree_Inferred` |
| **Ghidra name** | `FUN_00970fc0` |
| **Address** | `0x00970fc0`–`0x00971024` inclusive (**101 B** / `0x65`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Classification** | worker |
| **Name confidence** | **Inferred** — structural from AssPreloader dual family + ring/tree offsets; no PDB/method string on this VA |
| **Completion status** | **Dual-reviewed (W37-AD)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal coverage claim** | **false** |

## Purpose

Drain **host+0xAC** success/fail ring into membership tree **host+0xDC**: flag≠0 marks tree value 1; flag==0 runs fail helper. Pre-step for child-asset preload and worker loop.

## Signature

```c
void AssPreloader_DrainAcRingToTree_Inferred(void /*EAX=AssPreloader* host*/);
```

## Cross-links

- Twin Ghidra record: `functions/aa_00970fc0_FUN_00970fc0.md`
- Report: `docs/agents/task-dual-ab-00970fc0-004982d0-w37ad-report.md`
