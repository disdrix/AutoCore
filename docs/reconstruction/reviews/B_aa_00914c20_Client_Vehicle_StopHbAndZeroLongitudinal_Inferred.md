# Review B (skeptical / adversarial): `aa_00914c20` Client_Vehicle_StopHbAndZeroLongitudinal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00914c20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY dual B **MEGA-098** — live Ghidra) |
| **Counterpart** | `reviews/A_aa_00914c20_Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create/seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Also SetHandbrake / PushDriveAxes | Merge with Engage pack `00915670` | **Falsified** — only Stop + SetLong; 2 calls |
| 2 | `thiscall` ECX = client host | Standard MSVC member | **Falsified** — host in **EAX**; both sites `MOV EAX,EDI` |
| 3 | Runs whenever vehicle present | Ungated | **Falsified** — requires `DAT_00d1a860 != 0` **and** HB `+0xc70` |
| 4 | Stop only when `DAT_00d1a860 == 0` | Confuse with Engage optional Stop | **Falsified** — this body requires flag **non-zero** (opposite polarity) |
| 5 | Writes steer (`+0x618`) or thr damp | Overfit DriveControlTick | **Falsified** — only SetLong(0) on vehicle path |
| 6 | Many call sites | Incomplete graph | **Falsified for count** — **2** xrefs only |
| 7 | Inlined hub early block **is** this function | Identity merge | **Falsified** — hub has separate inline CF **plus** CALL at `00925984` to this leaf |
| 8 | Product name sealed | No string / PDB | **Fail** — `_Inferred` only |
| 9 | Ready for runtime Confirmed | Matrix | **Fail** — no Launcher; Terminal false |
| 10 | `push 0` is integer not float | Type nit | **Neutralized** — same 0 bits as `+0.0f`; callee stores f32 @ `+0x614` |

---

## 2. Decisive dataflow

```
// entry: EAX = client host (EDI at both sealed call sites)
if DAT_00d1a860 == 0: return
ECX = *(EAX + 0xc70)          // HB*
if !ECX: return
*(u8*)(EAX + 0xa35) = 0
CALL CVOGHBBase_Stop          // thiscall ECX=HB
EAX = DAT_00d1b6d8            // clobbers host
if !EAX: return
ECX = *(EAX + 0x250)          // vehicle*
if !ECX: return
push 0
CALL VehicleEntity_SetLongitudinalInput
ret
```

Live decompile 2026-08-05 ≡ 2026-07-23 raw.

Host EAX is intentionally clobbered after Stop; no further host field access.

---

## 3. Adversarial polarity check vs Engage sibling

| Unit | VA | `DAT_00d1a860` for Stop | Axis action |
|---|---|---|---|
| **This** StopHb+ZeroLong | `00914c20` | must be **non-zero** (outer gate) | SetLong(**0**) only |
| EngageHbAndPushAxes | `00915670` | optional Stop only if flag **zero** | HB=**1** + Push |

Polarity inversion is **evidence-backed**, not a misread: both dualed; do not merge.

---

## 4. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + clear + Stop + optional SetLong0 order | **High** | Wrong interact/drive park port |
| EAX host ABI | **High** | Wrong thiscall port |
| Two call sites only | **High** | Missed stop paths |
| Callee identities | **High** | Wrong HB/axis APIs |
| Latch `+0xa35` product meaning | **Open** | Naming only |
| Mode flag English | **Open** | Soft-path UX label |
| Runtime | **Open** | Parity residual |

---

## 5. Surviving contract for AutoCore

```
StopHbAndZeroLongitudinal(clientHost in EAX):
  if !DAT_00d1a860 || !*(clientHost+0xc70): return
  clientHost.latch_a35 = 0
  CVOGHBBase_Stop(*(clientHost+0xc70))
  vehicle = DAT_00d1b6d8 ? *(DAT_00d1b6d8+0x250) : null
  if vehicle: VehicleEntity_SetLongitudinalInput(vehicle, 0.0f)
```

**Port notes:**
- Do **not** implement as ECX-this member without an adapter that loads EAX.
- Do **not** fold into EngageHbAndPushAxes (opposite flag polarity; different axis/HB actions).
- Pair with dualed `CVOGHBBase_Stop` + `VehicleEntity_SetLongitudinalInput`.

**Verdict:** **accept-with-gaps** — adversarial claims on merge/ABI/polarity/call-count closed; product English + runtime open.
