# Function record: AnmTrackEvents_UnserializeOneEvent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fe10` |
| **Canonical name** | `AnmTrackEvents_UnserializeOneEvent_Inferred` |
| **Address** | `0x0044fe10` |
| **Body** | `0x0044fe10`–`0x0044fe65` (**86 B** / `0x56`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | anmTrackEvents / NestedHash factory dispatch |
| **Completion status** | **Dual A/B complete** (2026-07-29 W36-G) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0044fe10` |

## Purpose

Unserialize **one** track-event entry for `anmTrackEvents`:

1. `FUN_0076a900` — read FOURCC/key from **EDI** stoChunkReader.
2. `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred` (`FUN_0044fee0`) — bag pointer.
3. `FUN_0046c1b0` — NestedHash lookup by key → node (or sentinel).
4. If node ≠ bag sentinel at **+8**: thiscall factory at **node[+0xC]**.
5. Store object to `*out_event`; if non-null, thiscall **obj[+4]** with **EDI** pushed; return that status.
6. Else return **`0xffffffff`**.

## Signature

```c
uint32_t AnmTrackEvents_UnserializeOneEvent_Inferred(void **out_event);
/* EDI = stoChunkReader* register formal */
```

| Slot | Source | Conf |
|---|---|---|
| `out_event` | stack `[ESP+4]` at entry → `MOV [ECX],EAX` | **High** |
| EDI reader | `MOV ESI,EDI` then key-read; `PUSH EDI` before obj vcall | **High** |
| return | obj vtbl+4 result, or `OR EAX,-1` | **High** |
| cleanup | `ADD ESP,8; RET` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044fe10_FUN_0044fe10.md`
- Annotated: `docs/reconstruction/raw/aa_0044fe10_FUN_0044fe10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AnmTrackEvents_UnserializeOneEvent_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0044fe10.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0044fe10_FUN_0044fe10.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md`

## Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller (sole) | `FUN_00987750` | anmTrackEvents.cpp event-count loop |
| Callee | `FUN_0076a900` | key/FOURCC from reader |
| Callee | `FUN_0044fee0` | NestedHash0x10 static once-get |
| Callee | `FUN_0046c1b0` | NestedHash lookup |
| Virtual | node[+0xC] | event factory |
| Virtual | obj[+4] | event body unserialize |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| anmTrackEvents product role (via caller strings) | **High** |
| NestedHash0x10 bag + sentinel | **High** (W35-E) |
| Event C++ class name | Open |
| Dual review | Present |
