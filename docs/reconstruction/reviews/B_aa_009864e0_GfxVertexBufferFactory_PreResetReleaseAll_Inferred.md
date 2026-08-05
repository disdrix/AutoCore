# Review B (skeptical / adversarial): `aa_009864e0` GfxVertexBufferFactory_PreResetReleaseAll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009864e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-AD) |
| **Counterpart** | `reviews/A_aa_009864e0_GfxVertexBufferFactory_PreResetReleaseAll_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler correctly shows FUN_007465c0 with no register args | **Partial fail on decompiler** — bytes `8B 33` load ESI from slot before CALL; callee uses unaff_ESI |
| 2 | This is IB factory pre-reset | **Falsified** — caller loads device+0x74C (VB slot); callee is gfxDeviceVB not IB; IB twin is `00985580` on +0x750 |
| 3 | This is PostRestore / recreate | **Falsified** — no HRESULT return; called in shutdown block before D3D Reset; PostRestore is `00986570` after Reset succeeds |
| 4 | Flag test is at node+0xC (dword index 3) | **Falsified for this VA** — bytes `F6 47 0E 28` = TEST [EDI+0xE],0x28 (IB sibling decompile uses +0xC; not this body) |
| 5 | Stride is 4 (pointer vector) | **Falsified** — `83 C3 20` and PostRestore `piVar12 + 8` dwords |
| 6 | Multiple callers | **Falsified** — single xref `0x0075f0e7` |
| 7 | Infinite loop when isnil set without successor | **Mitigated** — only sentinel is nil end; loop exits when node==sentinel after successor lands on head |
| 8 | Scaffold name is product | **Rejected** — product path is sibling/callee strings; keep `_Inferred` factory English |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pre-reset release-all role | **High** | Wrong D3D reset phase |
| EAX factory @+0x74C | **High** | Wrong host |
| Tree + flag + 0x20 slots | **High** | Missed / double free |
| ESI → FUN_007465c0 | **High** | Silent no-op / crash |
| VB not IB | **High** | Wrong buffer class |
| Flag 0x28 English | **Low** | Naming only |
| Slot layout full plate | **Med** | Incomplete port of metadata |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller + sibling

```
// FUN_0075eff0 sequence:
//   CALL 00985f40  ; pool track notify
//   CALL 00985580  ; IB factory pre-reset (device+0x750)
//   CALL 009864e0  ; VB factory pre-reset (device+0x74C)  ← this
// FUN_007465c0: gfxDeviceVB.cpp "Unlock more times than locked"
// FUN_00986570: gfxVertexBufferFactory.cpp "Failed PostResoreDevice() on Vertex Buffers"
// Entry: 51 8B 48 14 57 8B 39 ...
// Exit:  5E 5D 5B 5F 59 C3 @ 0x00986560
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 skeleton; bytes seal ESI and +0xE flag.

---

## 4. Surviving contract for AutoCore

```
// Port as VB factory pre-reset release-all (not PostRestore):
//   factory = device.vbFactory; // +0x74C
//   for each map node (sentinel @ factory+0x14):
//     if (node.flags@+0xE & 0x28) == 0:
//       for slot in [begin@+0x14, end@+0x18) step 0x20:
//         GfxDeviceVB_UnlockAllAndRelease( *(GfxDeviceVB**)slot );
// Retail: EAX=factory; ESI per slot into FUN_007465c0; void.
// Do not return HRESULT; do not recreate buffers here.
// Do not merge with PoolHost vtbl walk (00985f40) or IB twin (00985580).
```

---

## 5. Verdict

Adversarial pass confirms A on factory ABI, tree walk, flag/stride, ESI callee contract, VB identity. Residual flag/slot English → **accept-with-gaps**.
