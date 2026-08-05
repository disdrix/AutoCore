# Review B (skeptical / adversarial): `aa_00972140` AssPreloader_PreloadWorkerLoop_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-K) |
| **Counterpart** | `reviews/A_aa_00972140_AssPreloader_PreloadWorkerLoop_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall / plain RET | **Falsified** — stack host load; **`RET 4`** |
| 2 | Infinite spin with no pending gate | **Falsified** — exits when `FUN_0043e510` on **host+0x1c** returns 0 |
| 3 | Loads all extensions | **Falsified** — only **`geo`→type 0** and **`xml`→type 3** call submit; other exts jump to success-record without load |
| 4 | `operator_delete` is noreturn (Ghidra warning) | **Falsified** — bytes continue; zero request fields; success-record still runs |
| 5 | Fail path erases pending via PushBack_Thiscall alone | **Partial** — bytes push under CS to **host+0x7c** (tracked); exact product “erase pending” English not sealed beyond call |
| 6 | Scaffold `Named_assPreloader_00972140` is full product method | **Overstated** — file string seals family; method English **Inferred** |
| 7 | Sole entry is free-function main | **Falsified** — only caller **`FUN_00972460`** thread trampoline (WaitForSingleObject on host+4) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack host + RET 4 + pending while | **High** | Hang / wrong object |
| Ticket + factory snapshot | **High** | Stale load / wrong generation |
| geo/xml type map | **High** | Wrong asset type |
| CS pairs +0x60/+0x78 and +0x90/+0xa8 | **High** | Race / deadlock |
| Success vec +0x4c / tracked +0x7c | **High** (bytes) | Wrong store |
| Fail-path product meaning | **Medium** | Mis-port recovery |
| Nested submit helpers | **Open** | Incomplete load path |
| Runtime | **Open** | Threading races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  while pending:
    drain; if ticket match:
      snapshot cache+0x28; try geo/xml load; success CS push or PRELOAD log; Sleep(0); clear

bytes:
  LEA ESI,[EBP+0x1C]; CALL 0043e510
  CMP ticket, *FUN_0044a860(+0xDC)
  LEA ECX,[cache+0x28]; CALL 0043c5f0
  strrchr / _stricmp "geo"/"xml"
  CALL 00971b80 / 00971280
  EnterCS(+0x60); CALL 0043e970; LeaveCS; *FUN_0043d700=1
  OR log assPreloader.cpp:0x212 + CS(+0x90) FUN_0043d670(+0x7c)
  Sleep(0); CALL 0040d9c0
  RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full 738 B hex sealed. Caller `FUN_00972460` decompiled: loops this + WaitForSingleObject(host+4).

---

## 4. Surviving contract for AutoCore

```
// AssPreloader preload worker loop body:
//   stack = AssPreloader* host; RET 4; void
//   while pending(+0x1c) non-empty:
//     drain; if ticket(+0xe0)==*probe(+0xdc):
//       snapshot cache factory list; try first path with ext geo|xml;
//       success: CS-guarded stride-2 push at +0x4c; flag=1
//       fail: log PRELOAD @ assPreloader.cpp:0x212; CS push to +0x7c
//       Sleep(0); clear local
// Thread trampoline FUN_00972460 owns WaitForSingleObject(*(host+4)).
// Do not treat operator_delete as noreturn. Do not invent method PDB name.
```

---

## 5. Verdict

Adversarial review confirms sealed worker-loop ABI/CF and product log path; nested submit + fail-path English remain gaps → **accept-with-gaps**.
