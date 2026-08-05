# Function record: UI_Case_CloseBtn_9c40

| Field | Value |
|---|---|
| **Stable ID** | `aa_00870e15` |
| **Canonical name** | `UI_Case_CloseBtn_9c40` |
| **Ghidra name** | `caseD_9c40` / `switchD_00870aaa::caseD_9c40` |
| **Address** | `0x00870e15` |
| **Body** | `0x00870e15`–`0x00870e43` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI dialog message switch (close control `0x9c40`) |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Jump-table **case arm** for UI control id **`0x9c40` (40000)** — the standard close-button id — inside parent dispatcher **`0x00870a90`** (`switch (controlId - 0x9c40)` range 0..11).

On **message 8** (click/activate): leave dialog via **`FUN_007fca10`** only when **`this+0x50c == -1`** (no selection); otherwise swallow the click. Always returns **1** on msg 8. Other messages forward to **`FUN_0087b500(this, msg, controlId)`**.

## Signature (byte-sealed)

```c
// Live registers from parent; stack cleaned with RET 8
uint32_t UI_Case_CloseBtn_9c40(
    void* this,          // EDI (from ECX at parent entry)
    int msg,             // EAX / [esp+4]
    uint32_t controlId   // EDX / [esp+8]  — 0x9c40 for this arm
);
```

Decompiler shows `__fastcall` + unused `param_1` and phantom `in_EAX`/`unaff_EDI` — **corrected by body bytes**.

## Sealed facts

1. **Role:** close-button case only; not packet builder; not mission HandleButton fill.
2. **Gate:** `*(int*)(this+0x50c) == -1` required before `FUN_007fca10`.
3. **Leave ABI:** EAX=`this`, EBX=`0x00d1a840` (static client base), then call `0x007fca10`.
4. **Forward:** `mov ecx,edi; push edx; push eax; call 0x0087b500`.
5. **Epilogue:** both tails `pop edi; ret 8`.
6. **Xrefs:** jumptable DATA `0x00870e44` → this VA; COMPUTED_JUMP from parent at `0x00870aaa`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00870e15_FUN_00870e15.md`
- Annotated: `docs/reconstruction/raw/aa_00870e15_FUN_00870e15.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_Case_CloseBtn_9c40.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00870e15_UI_Case_CloseBtn_9c40.md`
- Review B: `docs/reconstruction/reviews/B_aa_00870e15_UI_Case_CloseBtn_9c40.md`
- Legacy scaffold: `docs/reconstruction/reconstructed-exact/FUN_00870e15.cpp` (superseded by clean above)
- Report: `docs/agents/task-dual-ab-00870e15-ui-case-closebtn-9c40-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | Parent `0x00870a90` via jumptable[0] | Not a direct CALL; computed jump |
| Callee | `FUN_007fca10` @ `0x007fca10` | Leave host when unselected |
| Callee | `FUN_0087b500` @ `0x0087b500` | Non-msg-8 forward |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| msg==8 / +0x50c==-1 / leave / else forward | **High** |
| Parent register setup (EDI/EAX/EDX) | **High** |
| Product class name / selection English | **Open / Tentative** |
| Types beyond dword offsets | Tentative |
