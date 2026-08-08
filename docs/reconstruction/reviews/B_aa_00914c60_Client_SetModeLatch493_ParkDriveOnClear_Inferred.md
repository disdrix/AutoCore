# Review B (skeptical / adversarial): `aa_00914c60` Client_SetModeLatch493_ParkDriveOnClear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00914c60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY dual B **R11-037** — live Ghidra) |
| **Counterpart** | `reviews/A_aa_00914c60_Client_SetModeLatch493_ParkDriveOnClear_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create/seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **is** StopHb+ZeroLong leaf | Identity with `00914c20` | **Falsified** — this is wrapper; Stop only on clear path via CALL |
| 2 | Enable path also parks drive | Symmetric axes | **Falsified** — enable never calls `00914c20` / `007fb990` |
| 3 | Bare `RET` / no stack arg | void() | **Falsified** — `RET 4`; stack enable in EBX |
| 4 | Host in EAX at entry (like 14c20) | Copy parent ABI | **Falsified** — **ECX thiscall**; Stop leaf gets EAX via `MOV EAX,EDI` |
| 5 | `+0x538` is integer/hash clear | Mission hash at char+0x538 | **Falsified for store form** — `XORPS`/`MOVSS` **f32** zero; not mission-hash API |
| 6 | Many direct callers | Incomplete graph | **Falsified for count** — **0** CALL xrefs; **1** DATA vtable |
| 7 | Always notifies cursor host | Ungated | **Falsified** — notify gated by latch + host + query polarity |
| 8 | Query polarity same both paths | Uniform | **Falsified** — clear needs query **true**; enable needs query **false** |
| 9 | Writes latch `+0x493` inline | Local store | **Falsified** — only `FUN_007902a0` writes latch (body only reads) |
| 10 | Product name sealed | No string / PDB | **Fail** — `_Inferred` only |
| 11 | Ready for runtime Confirmed | Matrix | **Fail** — no Launcher; Terminal false |

---

## 2. Decisive dataflow

```
// entry: ECX = client (EDI), [esp+8] after push ebx = enable (BL)
if enable == 0:                          // clear
  if *(u8*)(EDI+0x493) == 0: goto tail
  ESI = 0x00d1a840
  CALL FUN_007fb990
  EAX = EDI
  CALL FUN_00914c20                      // StopHb+ZeroLong
  ECX = DAT_00d1b9a8
  if !ECX: goto tail
  AL = [ECX]->vtbl[+0xd0]()
  if AL == 0: goto tail
  push 0
  goto notify
else:                                    // enable
  if *(u8*)(EDI+0x493) != 0: goto tail
  ECX = DAT_00d1b9a8
  if !ECX: goto tail
  AL = [ECX]->vtbl[+0xd0]()
  if AL != 0: goto tail
  push 1
notify:
  ECX = DAT_00d1b9a8
  CALL [ECX]->vtbl[+4]
tail:
  *(f32*)(EDI+0x538) = 0.0f              // XORPS + MOVSS
  push enable ; ECX = EDI
  CALL FUN_007902a0                      // apply +0x493
  ret 4
```

Live decompile 2026-08-05 ≡ 2026-07-23 raw CF. Asm upgrades `+0x538` to f32 store.

---

## 3. Adversarial polarity check vs Stop leaf

| Unit | VA | Role | Drive park |
|---|---|---|---|
| **This** SetModeLatch493 | `00914c60` | latch + host notify + always float clear | **only when clearing** (calls leaf) |
| StopHb+ZeroLong | `00914c20` | shared park leaf | Stop HB + SetLong(0) under `DAT_00d1a860` |

Do **not** merge: wrapper owns latch/host; leaf owns park math.

---

## 4. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Enable/clear CF + latch gates | **High** | Wrong mode-toggle port |
| ECX thiscall + RET 4 | **High** | Wrong call ABI |
| Clear-only park via 14c20 | **High** | Spurious thr park on enable |
| f32 `+0x538` zero always | **High** | Wrong field type |
| Vtable-only dispatch | **High** | Missed direct callers (none found) |
| Host vtbl product meaning | **Open** | Naming only |
| Latch English `+0x493` | **Open** | UX label |
| Runtime | **Open** | Parity residual |

---

## 5. Surviving contract for AutoCore

```
SetModeLatch493_ParkDriveOnClear(client, enable):
  // thiscall ECX=client; stack enable; ret 4
  if !enable:
    if !client.latch_493: goto tail
    ui_cleanup(global_client=&DAT_00d1a840)   // FUN_007fb990
    StopHbAndZeroLongitudinal(client)         // EAX host
    if host && host.query(): host.notify(0)
  else:
    if client.latch_493 || !host: goto tail
    if !host.query(): host.notify(1)
tail:
  client.f32_538 = 0.0f
  ApplyLatch493(client, enable)               // FUN_007902a0
```

**Port notes:**
- Implement as **virtual member** (vtable `@00a2f468`); no static CALL sites in image.
- Do **not** park drive on enable path.
- Do **not** treat as EAX-host leaf (that is `00914c20` only).
- Pair with dualed `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred`.

**Verdict:** **accept-with-gaps** — adversarial merge/ABI/polarity/call-count/`+0x538`-type claims closed; product English + runtime open.
