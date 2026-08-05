# Review B (skeptical / adversarial): `aa_00966630` Gfx_DeviceStateCache_Clear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00966630` |
| **VA** | `0x00966630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00966630_Gfx_DeviceStateCache_Clear_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 68 B + sole caller + sibling init + stage consumer |
| **Agent** | W38-Y OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX is a real formal | Body never touches ECX; decompiler `param_1` phantom | **Falsified ECX formal** |
| 2 | thiscall on device object | Caller loads **EDX** from `DAT_00d1f048`, not ECX=this | **Falsified device-thiscall** |
| 3 | Full host destructor / free | Only zeros; no Release/delete; parent re-fills slots | **Falsified dtor** |
| 4 | Only clears host, not globals | Two `REP STOSD` on image globals | **Falsified host-only** |
| 5 | 0x10 is byte count | `REP STOSD` dwords → 16×4 = 64 B each table | **Sealed as 16 dwords** |
| 6 | Product name sealed as StatsMonitor | "Stats Monitor" is sibling factory fail string (`FUN_00966760`); host also holds timers in twin init | **Accepted gap** — structural name only |
| 7 | Multiple callers | Only `GfxDevice_Reset` xref | **Sealed 1 caller** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero two stage tables + scalars + host slots | **Confirmed** | Stale texture binds after Reset |
| EDX host ABI | **Confirmed** | Wrong register / crash |
| Leaf / no callees | **Confirmed** | — |
| Texture-stage cache role of tables | **Confirmed** (consumer) | Misnamed domain |
| Host product English | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers / twins

| Unit | Relation |
|---|---|
| `GfxDevice_Reset` @ `0x0075f48f` | Sole caller; `EDX=[DAT_00d1f048]`; then `host[0..2]=device slots` |
| `FUN_00966690` | Full init: assign `DAT_00d1f048`, floats/flags, **same zero block** |
| `FUN_00966680` | `DAT_00d1f048=0` only |
| `FUN_0043f4b0` | Reads/writes stage tables before D3D set-texture-class vcall |

---

## 4. Byte anchors

```text
0x00966630: 56 57                   ; PUSH ESI; PUSH EDI
            33 F6 33 C0             ; ESI=0; EAX=0
            B9 10 00 00 00          ; ECX = 16
            BF 28 E1 D0 00          ; EDI = DAT_00d0e128
            F3 AB                   ; REP STOSD
            B9 10 00 00 00
            BF E8 E0 D0 00          ; EDI = DAT_00d0e0e8
            F3 AB
            5F                      ; POP EDI
            89 35 68 A5 D1 00 …     ; four scalar stores
            89 32 89 72 04 89 72 08 89 72 3C  ; host zeros
            5E C3                   ; POP ESI; RET
```

---

## 5. What would reverse the seal?

- Proof of ECX formal or stack args — no loads of ECX / `[ESP+…]` args.
- Proof of COM Release inside — no indirect calls.
- Proof of second caller — only one xref.

None observed. **accept**.
