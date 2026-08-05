# Function record: Client_AppFrameTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094b520` |
| **Canonical name** | `Client_AppFrameTick` |
| **Ghidra name** | `FUN_0094b520` |
| **Address** | `0x0094b520` |
| **Body range** | `0x0094b520`–`0x0094b9b5` (exclusive end `0x0094b9b6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / main-loop frame |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/gates sealed; many callees product-open; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0094b520_Client_AppFrameTick.md`, `reviews/B_aa_0094b520_Client_AppFrameTick.md` |
| **Last reviewed** | `2026-07-29` (W20-A) |

## Alias

- `FUN_0094b520` (Ghidra)
- Auto parent-seed `Named_frametime_txt` — **misleading as sole role** (frametime path is one diagnostic arm)

## Purpose

**Application frame tick** for the client: sole body invoked each iteration of the Win32 message pump (`FUN_0094b9c0`). Gates on master flag and focus/UI poll, then runs an ordered sequence of subsystem ticks (input, heartbeat list, session, UI event queue, optional load-queue / frametime log), ends with `Sleep(0)` and always returns **1**.

## Signature

```c
uint32_t __fastcall Client_AppFrameTick(void *client /* ECX */);
// bare ret; EAX = 1 always
```

## Algorithm (ordered)

1. SEH + large chkstk frame (100k log buffer).
2. If `client+0x13 == 0` → restore SEH, return 1.
3. Timer nest A (`DAT_00d09874+0x25` / QPC `+0x170`), `FUN_0094b3a0`, profile leave 5.
4. If `client+0xf40 == 0` → skip body.
5. Timer nest B (`+0x27` / QPC `+0x180`).
6. If `Client_Input_FocusGateAndUiPoll_Inferred(0) != 0` → skip body.
7. Else: profiled subsystem sequence (see clean plate), including:
   - optional `FUN_0079a0d0` when `+0xa1==0`
   - when `+0xb7`: `FUN_00932c80`, `CVOGHBList_Tick(+0xd38,0)`, `FUN_0093da30`, …
   - `FUN_00938380`, optional vcall on `+0xdec`, session work on `+0xe04`
   - LoadQueue focus test + optional `FUN_004bfe10(0x3b888889)`
   - dt-scaled `FUN_004cd7c0` / `FUN_004d18a0`
   - `FUN_00944770` then **`Client_DispatchUiEventQueue`**
   - optional `..\logs\frametime.txt` append
   - `Sleep(0)`, profile enter 0, `FUN_0079a9f0`, `FUN_0092cd20`
8. Restore ExceptionList; return 1.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0094b520_FUN_0094b520.md`
- Annotated: `docs/reconstruction/raw/aa_0094b520_FUN_0094b520.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_AppFrameTick.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0094b520.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00512060-0094b520-w20a-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | Sole: `FUN_0094b9c0` @ `0x0094b9e4` (message pump) |
| **High-signal callees** | `FUN_0093a5c0` (FocusGate mode 0), `CVOGHBList_Tick`, `FUN_00946c00` (DispatchUiEventQueue), `QueryPerformanceCounter`, `Sleep`, `fopen`/`fputs`/`fflush` |
| **Profile wrappers** | `FUN_0079a1c0` / `FUN_0079a120` ids 0,1,5–0xc |
| **Strings** | `..\logs\frametime.txt`, `LoadQueue test, focus = %d` |

## Confidence

| Claim | Level |
|---|---|
| Role = app frame tick of main pump | **High** (sole caller loop + subsystem fan-out) |
| ECX = client*, return 1 | **High** |
| Gate offsets `+0x13/+0xa1/+0xb7/+0xf40/+0xe04` | **High** (decompile ≡ raw) |
| Product English for flags / whole unit | **Open** |
| Full product map of every FUN_* arm | **Partial** |
| Runtime / bit-exact | Open |

## Related

- `aa_0093a5c0` Client_Input_FocusGateAndUiPoll_Inferred (arg 0 here)
- `aa_00507950` CVOGHBList_Tick
- `aa_00946c00` Client_DispatchUiEventQueue
- Pump outer: `FUN_0094b9c0` (not owned this dual)
