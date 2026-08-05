# Review B (skeptical / adversarial): `aa_00754280` Palantir_StartPreloadThread_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-F) |
| **Counterpart** | `reviews/A_aa_00754280_Palantir_StartPreloadThread_Inferred.md` |
| **Scratch** | `tmp/a_00754280.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — host is **EDI**; no ECX use on entry |
| 2 | Always creates thread | **Falsified** — early AL=0 when `+0xd4` set |
| 3 | Returns bool in EAX full dword only | **Partial** — only AL written (`32 C0` / `B0 01`); upper EAX undefined as usual |
| 4 | Decompiler shows full create args | **Falsified** — decompile drops ESI/EDX/AL; **bytes seal** create contract |
| 5 | Product name retail | **Overstated** — inferred from plates |
| 6 | Safe on OOM | **Falsified as "safe"** — stores null and still calls create; retail CF only |
| 7 | Same as AssManager resolver init | **Falsified** — only preload thread; AssManager also calls `00989ef0` separately |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI host + plain RET + AL | **High** | Wrong object / return |
| `+0xd4` thrThread slot | **High** | Double-start / leak |
| thrThread 0x10 + vftable | **High** | Wrong object type |
| EDX=0x40000 stack | **High** | Stack starvation |
| Product English | **Inferred** | Naming only |
| CreateThread start body | **Open** | Preload work residual |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if +0xd4: log; return 0
  new(0x10); optional init; store +0xd4; FUN_0071aef0(); return 1

bytes (105 B):
  PUSH ESI; XOR ESI,ESI
  CMP [EDI+D4],ESI / JZ alloc
  log path; XOR AL,AL; POP ESI; RET
  PUSH 10 / operator_new
  optional thr init; MOV ESI,EAX
  MOV EDX,40000; XOR AL,AL
  MOV [EDI+D4],ESI; CALL FUN_0071aef0
  MOV AL,1; POP ESI; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full hex sealed. Byte-level create args **beyond** decompile.

Polarity vs disable path `FUN_00934420` ("Preloading disabled" → `FUN_00754230`): this unit is **start-only**.

---

## 4. Surviving contract for AutoCore

```
// Palantir preload thrThread start (once):
//   EDI = host (*DAT_00d1f058 at known clients)
//   if host+0xd4 != 0: log already-running; return AL=0
//   thr = new thrThread(0x10) or null
//   thr.vftable = PTR_FUN_00a9e9bc; thr.context = *(DAT_00d1f050+0x6c)
//   host+0xd4 = thr
//   thrThread_Create(ESI=thr, EDX=0x40000, AL=0)  // FUN_0071aef0
//   return AL=1
// Do not invent ECX-thiscall or stack formals.
// Do not invent "fail on OOM" — retail returns 1 anyway.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/strings; create-arg bytes fix decompiler gap; residuals are product name + thrThread start body + OOM realism → **accept-with-gaps**.
