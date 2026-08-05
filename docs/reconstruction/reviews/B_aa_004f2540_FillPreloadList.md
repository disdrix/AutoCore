# Review B (skeptical / adversarial): `FillPreloadList` / `FUN_004f2540` @ `0x004f2540`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f2540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-L) |
| **Counterpart** | `reviews/A_aa_004f2540_FillPreloadList.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Name is invented / scaffold only | **Falsified** — profiler push of `"FillPreloadList"` @ `0x009cd090` |
| 2 | PushFront targets dep ring `+0x110` | **Falsified** — bytes `MOV ECX,EBX` with EBX=`self+0x124` before `CALL 0043e3d0` |
| 3 | `FUN_0043d650` clears `+0x110` | **Falsified** — same EBX=`+0x124` for clear call |
| 4 | Multiple CALL sites | **Falsified** — sole unconditional CALL `005c73c1` |
| 5 | Always runs Anim/Phy/Snd | **Falsified** — gated on `*(DAT_00d1f050+0x6c)` |
| 6 | Type-3 always | **Falsified** — only when clonebase `+0x3f4==3`; else primary key |
| 7 | stdcall / stack this | **Falsified** — `MOV ESI,ECX` + bare `C3` |
| 8 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Plate / CF / return 0\|1 | **High** | Wrong stage name / fail path |
| Primary ring @+0x124 | **High** | Fills wrong vector |
| Dep ring @+0x110 | **High** | Deps lost / mixed |
| Gate + domain collectors | **High** | Missing preload domains |
| `.spt` type==3 | **High** | Wrong key for SPT assets |
| Host class English | **Medium** | Docs only |
| Runtime | **Open** | Edge empty clonebase |

---

## 3. Cross-check against raw + bytes

- Live decompile **≡** 2026-07-23 raw for high-level CF.  
- Bytes **supersede** decompiler on ECX for `FUN_0043d650` and `GuardedVector_PushFront_Thiscall` (both `self+0x124`).  
- Full hex: raw W32-L append (406 B ending `C3`).  
- `.spt` bytes `2e 73 70 74` confirmed via `read_memory 0x009cd088`.

---

## 4. Surviving contract for AutoCore

```
// FillPreloadList — ECX load host; return 0 if name@+0x188 empty/space
// Clear primary GuardedVector @+0x124
// Hash name → key; collect transitive deps into +0x110 via 0x00744360
//   with ECX = *(DAT_00d1f050+0x64)
// Optional CollectAllGraphicsPreloads into +0x124 when gate@manager+0x6c
// If clonebase(+0x3c)->+0x3f4 == 3: push hash(name+".spt") else push key
//   via GuardedVector_PushFront_Thiscall(ECX=+0x124)
// Optional Anim@+0x138 / Phy@+0x14c / Snd@+0x160 collectors
// Sole caller: CLoadNode__initPreload when clonebase +0x134 == 0
```

---

## 5. Verdict

Adversarial pass **confirms** A on structural CF/ABI/plate; product host class residual → **accept-with-gaps**.
