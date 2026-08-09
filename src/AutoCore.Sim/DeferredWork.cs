// ============================================================================
// AutoCore.Sim — DEFERRED WORK REGISTER
// ============================================================================
// Living list of known issues and follow-ups explicitly deferred by the user
// (last updated 2026-08-09, after the /clonestartpath live sessions). Each
// entry records everything learned so work can resume without re-discovery.
// Companion history: the commit log of feature/clone-sim documents each fix
// attempt in detail; the tests named below pin current behavior.
//
// PERMANENTLY DROPPED (user decision — do not re-offer):
//   paint cloning, orbit tuning, flipped-clone recovery.
//
// ----------------------------------------------------------------------------
// 1. BRICK-STORE / TIGHT-LANE PATH STUCK  (deferred 2026-08-09, "no better")
// ----------------------------------------------------------------------------
// Symptom: /clonestartpath on arkbaytutorial path 'realgunny2' (66 points)
// reliably blocks at the brick store (obj_gen_n_static_str_02_brick-2story-
// store01, coid 15097, placed at (1178.85, 88.12, 2117.76), yaw ~87deg) around
// world position (1183, 2112), recovers 1-2 times, then continues.
//
// Everything ruled out / fixed along the way (all still in place):
//   - Fixed 6 m accept radius vs authored AcceptDistance 15 (waypoint 56 is
//     authored ~1 m from the store's east face) — accepts are honored now.
//   - Direct-to-waypoint chord cutting — replaced by ARC-LENGTH lane
//     following (CloneDriveBrain.PathInputs: reference projected onto the
//     polyline near its previous value, 9 m lookahead along the arc, loop
//     wrap / ping-pong reflection; vertices are never aim targets).
//   - Single-vertex corner slowdown — replaced by a braking envelope over
//     all vertices within a 45 m arc horizon (dense 10-20 m legs need
//     multi-leg braking from cruise).
//   - Convex-envelope collision: pieces named "_pNN" (this store: _p01.._p12)
//     were not scanned (only "-pN"), so the builder fell back to the solid
//     convex BASE hull whose envelope bulges across the alley. Both namings
//     load now (MapCollisionWorldBuilder.ResolveHulls).
//
// Root blocker that remains: piece-level analysis (world AABBs at the fam
// placement) shows the AUTHORED POLYLINE ITSELF clips the store's real south
// wall at car height — segment wp57 (1177.1, 2111.0) -> wp56 (1184.8, 2117.5)
// enters piece p09 (x 1175.4..1186.3, y 88.0..93.0, z 2112.6..2113.7) at
// x ~= 1179. Retail NPCs presumably thread this via per-NPC PATH LANE OFFSETS
// (NpcAiState.PathLaneOffset exists in AutoCore.Game and is used by the
// retail-parity path movers) and/or different traversal semantics.
//
// Next steps when resumed:
//   a) RE how retail computes/uses PathLaneOffset for patrol vehicles and
//      apply the same offset to the arc reference (shift the lane laterally).
//   b) Alternatively, an obstacle-aware local lane deformation: when the
//      lookahead lane point is inside/near a hull, slide it along the hull
//      surface (tangent) instead of recovering after contact.
//   c) Verify with the exact-geometry regression
//      ClonePathRouteTests.RealGunnyAlley_SweepsTheStoreCornerWithoutSticking
//      (real _p01.._p12 fixtures under Fixtures/hulls/store at the probed
//      placement) — tighten its allowance (currently <= 4 recoveries) toward
//      zero-touch as parity improves.
//
// ----------------------------------------------------------------------------
// 2. RAM-KILL DESTRUCTION REPLICATION  (deferred 2026-08-09)
// ----------------------------------------------------------------------------
// The clone drives through soft destructibles (street lights, crates) and
// kills them server-side via VehicleMapPropRam.Process, but nearby clients do
// NOT see the prop destroyed. Attempted fix: server-driven rammers now die
// DeathType.Violent (VehicleMapPropRam.ResolveRamDeathType) so
// GraphicsObject.OnDeath -> BroadcastDeath sends the visible
// InitCreateObject-DoDeath packet — this was NOT sufficient live.
// Player rams look right only because the ramming CLIENT simulates the
// destruction locally; other viewers never see server-driven kills either.
// Next step: RE how the client applies InitCreateObjectPacket(doDeath) /
// DestroyObjectPacket to CLIENT-LOCAL fam objects (addressed by local COID,
// never ghosted) — weapon kills of mission destroy-targets reportedly work,
// so compare that packet path against what BroadcastDeath emits for ram kills
// (deathType, murderer TFID, init-vs-destroy choice, force flag).
//
// ----------------------------------------------------------------------------
// 3. CORNERING PARITY  (deferred 2026-08-09, "good enough for now")
// ----------------------------------------------------------------------------
// RaycastCar turning is tuned from wheelset friction data (mu 3-5 from
// WheelSetSpecific.Friction shorts) and judged "much better — good enough".
// Remaining parity gaps vs the client: per-axle grip split
// (RearWheelFrictionScalar per axle rather than a lump), the retail
// 16-entry circle-projection friction LUT (we L2-renormalize), and the
// retail steering ramp shape (stage-1 rate seed ~20/7 with open-band x2;
// we use the +/-0.05-per-substep stage-2 only). Specs:
// docs/reconstruction/physics/steering-spec.md, 0.3-friction-solver.md.
//
// ----------------------------------------------------------------------------
// 4. GHOST SMOOTHNESS  (deferred 2026-08-09, "passable, improve later")
// ----------------------------------------------------------------------------
// Remote view of the clone is adequate but not perfect at the 20 Hz sector
// tick. If revisited: richer angular-velocity packing, evaluating the
// keep-dirty stage (ForcePathVehiclePoseDirty skips pathless clones — we rely
// on ApplyServerMove dirtying every tick), and possibly a higher pose rate
// for sim vehicles. Verify from a second client (see item 6).
//
// ----------------------------------------------------------------------------
// 5. CREST LAG ("low gravity" over hill crests)  (deferred 2026-08-09)
// ----------------------------------------------------------------------------
// After cresting a climb the body settles back onto level ground noticeably
// slowly. Suspension down-pull is capped at 2 g so jump exits stay ballistic;
// the fix sketch (see TODO in RaycastCar.Substep): raise or speed-scale the
// down-pull cap when the contact gap opened from BELOW (crest) rather than
// from terrain dropping away (jump).
//
// ----------------------------------------------------------------------------
// 6. TERRAIN TRIANGULATION MATCHING  (deferred 2026-08-09 — user wants to
//    iterate on this personally after the phases)
// ----------------------------------------------------------------------------
// Residual +/-0.2..0.5 m height wobble between maps/spots: the server samples
// the height16 grid BILINEARLY while the client renders a TRIANGULATED mesh;
// between grid points the surfaces disagree depending on which diagonal the
// client splits each quad on. Fix: RE CVOGTerrain's mesh build (per-cell
// diagonal choice), then replace MapTerrainHeightfield.TrySample's bilinear
// blend with the matching two-triangle barycentric interpolation. Benefits
// every NPC, not just clones. (The big win already landed: worldY =
// height16 * 1000 / 65280, pinned to 1-2 cm by live cross-map calibration.)
// /clonetrim remains as the live knob meanwhile.
//
// ----------------------------------------------------------------------------
// 7. LIVE VERIFICATION GAPS  (never observed, low risk)
// ----------------------------------------------------------------------------
// - Second-client scope: confirm the clone ghosts into ANOTHER player's view
//   correctly (create packets, driver creature, motion smoothness).
// - NPC aggro: confirm hostile NPC combat AI ignores the clone (it is
//   invincible so damage is safe, but target-acquisition/leash behavior
//   toward it has not been watched live).
// ============================================================================

namespace AutoCore.Sim;

/// <summary>Anchor for the deferred-work register above (no runtime behavior).</summary>
internal static class DeferredWork
{
}
